#!/usr/bin/env python
import pyrealsense2 as rs
import numpy as np
import math
from scipy.spatial.transform import Rotation as R
import time
import torch
from sensor_msgs.msg import PointCloud2, PointField


class Cameras:
    def __init__(self):
        # Declare RealSense pipeline, encapsulating the actual device and sensors
        self.pipe = rs.pipeline()

        # Build config object and request pose data
        cfg = rs.config()
        cfg.enable_stream(rs.stream.pose)

        # Start streaming with requested config
        self.pipe.start(cfg)

        for x in range(5):
            self.pipe.wait_for_frames()

    def callback(self, pointcloud):
        frames = self.pipe.wait_for_frames()
        
        # Fetch pose frame
        pose = frames.get_pose_frame()
        data = pose.get_pose_data()
        
        pos = data.translation
        vel = data.velocity
        acc = data.acceleration
        rot = data.rotation
        ang_vel = data.angular_velocity
        ang_acc = data.angular_acceleration
        #RobotPos = [pos.x * -1, pos.z, pos.y]
        RobotPos = self.TransPoint(np.array([pos.x, pos.y, pos.z]))
        #RobotVel = [vel.x * -1, vel.z, vel.y]
        RobotVel = self.TransPoint(np.array([vel.x, vel.y, vel.z]))
        #RobotAcc = [acc.x * -1, acc.z, acc.y]
        RobotAcc = self.TransPoint(np.array([acc.x, acc.y, acc.z]))
        r = R.from_quat([rot.x, rot.y, rot.z, rot.w])
        Rot_vec = r.as_rotvec()
        #RobotRot = [(Rot_vec[0] * -1) - 0.194, Rot_vec[2], Rot_vec[1]]
        RobotRot = self.TransPoint(np.array([Rot_vec[0], Rot_vec[1], Rot_vec[2]]))
        
        tf_cloud = self.TransCloud(pointcloud)
        start = time.perf_counter()
        points = self.key_points(torch.tensor(tf_cloud))        
        elaps = time.perf_counter() - start
        return tf_cloud, RobotPos, RobotVel, RobotAcc, RobotRot, ang_vel, ang_acc, points, elaps


    def euler_from_quaternion(self, x, y, z, w):
        """
        Convert a quaternion into euler angles (roll, pitch, yaw)
        roll is rotation around x in radians (counterclockwise)
        pitch is rotation around y in radians (counterclockwise)
        yaw is rotation around z in radians (counterclockwise)
        """
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll_x = math.atan2(t0, t1)
     
        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = math.asin(t2)
     
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw_z = math.atan2(t3, t4)
     
        return roll_x, pitch_y, yaw_z # in radians 

    def TransPoint(self, point):
        x_rot = -11-90 #placed in 61 degrees than 29+90 =119, 61+90=151
        y_rot = 180 #Guessed
        z_rot = 0 #Guessed

        omega = math.radians(x_rot)
        theta = math.radians(y_rot)
        kappa = math.radians(z_rot)

        tx = 0.0 # unsure of the unit
        ty = 0.0 # 
        tz = 0.0 # 

        ###############################################################
        # Rotation and translation matrices
        point = np.append(point, 1)
        rotMat_x = np.array([   [1, 0, 0, 0],
                                [0, math.cos(omega), math.sin(omega), 0],
                                [0, -(math.sin(omega)), math.cos(omega), 0],
                                [0, 0, 0, 1]    
                            ])
        rotMat_y = np.array([   [math.cos(theta), 0, -(math.sin(theta)), 0],
                                [0, 1, 0, 0],
                                [math.sin(theta), 0, math.cos(theta), 0],
                                [0, 0, 0, 1]    
                            ])
        rotMat_z = np.array([   [math.cos(kappa), math.sin(kappa), 0, 0],
                                [-(math.sin(kappa)), math.cos(kappa), 0, 0],
                                [0, 0, 1, 0],
                                [0, 0, 0, 1]    
                            ])
        projection_mat = np.matmul(np.matmul(rotMat_x, rotMat_y), rotMat_z)
        tf_point = np.matmul(point,projection_mat)  
        tf_point = np.delete(tf_point, 3)
        return tf_point


    def TransCloud(self, pointCloud):

        x_rot = -26.7-90 #placed in 61 degrees than 29+90 =119, 61+90=151
        y_rot = 0 #Guessed
        z_rot = 180 #Guessed

        omega = math.radians(x_rot)
        theta = math.radians(y_rot)
        kappa = math.radians(z_rot)

        tx = 0.057 # unsure of the unit
        ty = 0.040 # 
        tz = 0.39 # 

        ###############################################################
        # Rotation and translation matrices

        rotMat_x = np.array([   [1, 0, 0, 0],
                                [0, math.cos(omega), math.sin(omega), 0],
                                [0, -(math.sin(omega)), math.cos(omega), 0],
                                [0, 0, 0, 1]    
                            ])
        rotMat_y = np.array([   [math.cos(theta), 0, -(math.sin(theta)), 0],
                                [0, 1, 0, 0],
                                [math.sin(theta), 0, math.cos(theta), 0],
                                [0, 0, 0, 1]    
                            ])
        rotMat_z = np.array([   [math.cos(kappa), math.sin(kappa), 0, 0],
                                [-(math.sin(kappa)), math.cos(kappa), 0, 0],
                                [0, 0, 1, 0],
                                [0, 0, 0, 1]    
                            ])

        projection_mat = np.matmul(np.matmul(rotMat_x, rotMat_y), rotMat_z)
        tf_cloud = np.matmul(pointCloud,projection_mat)  
        tf_cloud = np.delete(tf_cloud, 3, 1)
        #tf_cloud = cloud.dot(projection_mat)
        tf_cloud[:,0] += tx
        tf_cloud[:,1] += ty
        tf_cloud[:,2] += tz
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,1] > -0.15), axis=0) # Remove points closer than 0.2 meters of the robot
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,1] < -1.25), axis=0)
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,0] > 1.2), axis=0)
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,0] < -1.2), axis=0)

        return tf_cloud

    def heightmap_distribution(self, delta=0.1, front_heavy=0.0, limit=1.2):

        point_distribution = []

        # If delta variable not set, exit.
        if delta == 0.0:
            print("Need delta value!")
            exit()

        y = 0.296
        while y < limit:
            
            x = 0.0

            delta += front_heavy

            while x < self.limit_x(y):
                
                if x == 0.0:
                    point_distribution.append([-x, -y])
                else:
                    point_distribution.append([-x, -y])
                    point_distribution.append([x, -y])
                
                x += delta

            y += delta

        point_distribution = np.round(point_distribution, 4)
    

        return point_distribution

    def limit_x(self, x):
        return x*(0.24555/0.296)+0.13338

    def key_points(self, heightData):
        # type: (Tensor) -> (Tensor)
        device = torch.device('cuda:0')
        # N = 50 # Number of key points
        # probability = np.zeros(len(heightData))
        heightmap_distribution = self.heightmap_distribution( delta=0.1, limit=1.2,front_heavy=0.0)
        # Create a matrix for the sampled data
        sampled_heightData = torch.empty((len(heightmap_distribution),3), device = device)
        # Create a empty vector for summing the values
        summer = torch.zeros(len(heightData[:,0]), device=device)
        # Convert numpy to torch tensor
        #data = torch.tensor(heightData)
        data = heightData.to(device)
        # Get the 10% heighest points
        p = 1
        height_threshhold = 0.001 # cm
        height_sum_threshhold = 0.5 # 
        #start = time.time()

        # for i in range(0,20):
        #     for j in range(0,20):
        #         summer = torch.where((i/100 >= data[:,0]) & (data[:,0] > i/100-0.1) & (j/100 <= data[:,1]) & (data[:,1] < j/100+0.1), data[:,2], 0.0)

        #print(data.shape)
        #print(data[0:30])
        for i, point in enumerate(heightmap_distribution):
            x = point[0]
            y = point[1]
            sampled_heightData[i,0] = x
            sampled_heightData[i,1] = y
            summer = torch.where((x+0.05 >= data[:,0]) & (data[:,0] > x-0.05) & (y-0.05 <= data[:,1]) & (data[:,1] < y+0.05), data[:,2], 0.0)
            if(torch.logical_not(torch.sum(summer) == 0.0)):
                # Remove points below threshhold
                B = summer[summer != 0.0]
                #rint(B)
                # Get number of points above threshhold
                n  = B.shape[0]
                sampled_heightData[i,2] = B.sum().item()/int(n*p)
            else:
                sampled_heightData[i,2] = 0
        # for i in range(0, 20):
        #     y = i/10    # Convert to meter (0-2m)
        #     y = -y      # Invert 
        #     for j in range(0, 20):
        #         x = j/10    # Convert to meter (0-2m)
        #         x = x - 1   # Offset -1m so that the range is (-1 to 1 meter)
        #         summer = torch.where((x >= data[:,0]) & (data[:,0] > x-0.1) & (y <= data[:,1]) & (data[:,1] < y+0.1), data[:,2], 0.0)
        #         if(torch.logical_not(torch.sum(summer) == 0.0)):
        #             # Remove points below threshhold
        #             #print(summer.shape)
        #             B = summer[summer != 0.0]
        #             #rint(B)
        #             # Get number of points above threshhold
        #             n  = B.shape[0]
        #             sampled_heightData[j,i] = B.sum().item()/int(n*p)
        #         else:
        #             sampled_heightData[j,i] = 0
        # for i in range(0, -200, -10):
        #     for j in range(-100, 100, 10):
        #         summer = torch.where((i/100 >= data[:,0]) & (data[:,0] > i/100-0.1) & (j/100 <= data[:,1]) & (data[:,1] < j/100+0.1), data[:,2], 0.0)
        #         if(torch.sum(summer) > height_sum_threshhold):
        #             # Remove points below threshhold
        #             B = summer[summer > height_threshhold]
        #             # Get number of points above threshhold
        #             n  = B.shape[0]
        #             sampled_heightData[int((abs(i))/10),int((j+100)/10)] = summer[0:int(n*p)].sum().item()/int(n*p)
        #             # print("hej" + str(sampled_heightData))
        #             # print(sampled_heightData.shape)
        #         else:
        #             sampled_heightData[int((abs(i))/10),int((j+100)/10)] = 0

        #print(sampled_heightData)
        return sampled_heightData

    
