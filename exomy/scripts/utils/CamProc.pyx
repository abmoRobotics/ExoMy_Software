import numpy as np
import math
from scipy.spatial.transform import Rotation as R
import time
import torch
from sensor_msgs.msg import PointCloud2, PointField
import csv


def key_pointsF(heightData, heightmap_distribution):
        # type: (Tensor) -> (Tensor)
        device = torch.device('cpu')
        # N = 50 # Number of key points
        # probability = np.zeros(len(heightData))
        
        # Create a matrix for the sampled data
        sampled_heightData = torch.empty((len(heightmap_distribution),3), device = device)
        # Create a empty vector for summing the values
        summer = torch.zeros(len(heightData[:,0]), device=device)
        # Convert numpy to torch tensor
        #data = torch.tensor(heightData)
        data = heightData.to(device)
        # Get the 10% heighest points
        cdef float p, n
        p = 0.1
        height_threshhold = 0.001 # cm
        height_sum_threshhold = 0.5 # 
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
                B, indices = B.sort(descending=True)
                B = B[0:int(n*p+1)]
                sampled_heightData[i,2] = B.sum().item()/int(n*p+1)
            else:
                sampled_heightData[i,2] = 0

        return sampled_heightData


    def TransPoint(point):
        cdef int x_rot, y_rot, z_rot
        cdef float omega, theta, kappa, tx, ty, tz
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
        cdef float x_rot, y_rot, z_rot
        cdef float omega, theta, kappa, tx, ty, tz

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
        # tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,1] > -0.15), axis=0) # Remove points closer than 0.2 meters of the robot
        # tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,1] < -1.25), axis=0)
        # tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,0] > 1.2), axis=0)
        # tf_cloud = np.delete(tf_cloud, np.where(tf_cloud[:,0] < -1.2), axis=0)

        return tf_cloud