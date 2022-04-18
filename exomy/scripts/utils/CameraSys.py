import pyrealsense2 as rs
import numpy as np
import math


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
        RobotPos = [pos.x * -1, pos.z, pos.y]
        RobotVel = [vel.x * -1, vel.z, vel.y]
        RobotAcc = [acc.x * -1, acc.z, acc.y]

        new_cloud = self.TransCloud(pointcloud)
        return new_cloud, RobotPos, RobotVel, RobotAcc, rot, ang_vel, ang_acc





    def TransCloud(self, pointCloud):

        x_rot = -26.7-90 #placed in 61 degrees than 29+90 =119, 61+90=151
        y_rot = 0 #Guessed
        z_rot = 2 #Guessed

        omega = math.radians(x_rot)
        theta = math.radians(y_rot)
        kappa = math.radians(z_rot)

        tx = -0.057 # unsure of the unit
        ty = -0.040 # 
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
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,1] < 0.05), axis=0) # Remove points closer than 0.2 meters of the robot
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,1] > 2), axis=0)
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,0] > 0.7), axis=0)
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,0] < -0.7), axis=0)

        return tf_cloud




