import pyrealsense2 as rs
import numpy as np
import math
from scipy.spatial.transform import Rotation as R
import time
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
        r = R.from_quat([rot.x, rot.y, rot.z, rot.w])
        Rot_vec = r.as_rotvec()
        RobotRot = [(Rot_vec[0] * -1) - 0.194, Rot_vec[2], Rot_vec[1]]
        
        tf_cloud = self.TransCloud(pointcloud)
        return tf_cloud, RobotPos, RobotVel, RobotAcc, RobotRot, ang_vel, ang_acc


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
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,1] > -0.05), axis=0) # Remove points closer than 0.2 meters of the robot
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,1] < -2), axis=0)
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,0] > 0.7), axis=0)
        tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,0] < -0.7), axis=0)

        return tf_cloud




