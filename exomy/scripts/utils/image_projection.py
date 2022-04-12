#from cv2 import norm
import numpy as np
import math
import matplotlib.pyplot as plt
#import matplotlib.image as mpimg #not used
#import matplotlib.tri as tri
#import matplotlib.axes as axes
#from scipy.interpolate import griddata
#import scipy.stats as statis
#import random
#from skimage.morphology import dilation
#import open3d as o3d
import torch
import time
###############################################################
# Image transformation

x_rot = 119 #placed in 61 degrees than 29+90 =119
y_rot = -3 #Guessed
z_rot = 5 #Guessed

omega = math.radians(x_rot)
theta = math.radians(y_rot)
kappa = math.radians(z_rot)

tx = 0 # unsure of the unit
ty = 150 # mm
tz = 100 # mm

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

trans_mat = np.array([  [1, 0, 0, tx],
                        [0, 1, 0, ty],
                        [0, 0, 1, tz],
                        [0, 0, 0, 1] 
                    ])

def load_pc(img):
    ###############################################################
    # Compute homography matrix and apply to input

    projection_mat = np.matmul(np.matmul(np.matmul(rotMat_x, rotMat_y), rotMat_z), trans_mat)
    tf_img = img.dot(projection_mat)  


    height_map(tf_img, img)
    #plot_pc(tf_img, img)

def height_map(tf_img, img):
    ##############################################################
    # Rearrange matrixes to get x, y as bird and maintain z axis from camera
    # Copy z axis from original to transformed and keep only x, y, and z axis in transform matrix
    tf_img = np.insert(tf_img, 2, img[:,2], axis=1)
    tf_img = np.delete(tf_img, 3, 1)
    tf_img = np.delete(tf_img, 3, 1)

    #tf_img = tf_img[::5,:] # Poor, non generalizing down sampling
    #heightData = heightData[heightData[:,0]%5==0] # Poor generalization
    
    heightData = tf_img * 100 # Convert from meters to centimeters
    heightData = heightData.astype(int) # Convert to integers
           
    x = heightData[:,0]
    y = heightData[:,1]
    z = heightData[:,2]

    # Generalize z axis
    h = np.where(z > 4) # Find threshold for exomy
    for i in z:
        if (min(h)[0] < i) and (i < max(h)[0]):
            z[i] = 6
    


    ####################################
    ###### Downsample data to 20x20 grid
    # Iterate through y and then for each yi, go through all x according
    # the collective z values must for the highest half find the mean.
    h = torch.tensor(heightData)
    start = time.time()
    key_arr = key_points(h)
    end = time.time()
    print(end-start)

    plt.scatter(key_arr[:,1], key_arr[:,0], marker='o', s = 5, zorder = 10, color='r') # plot points on grid
    
    ##### Mapping the irregular data onto a regular grid and plotting
    xic = np.linspace(min(x), max(x), 1000)
    yic = np.linspace(min(y), max(y), 1000)
    zic = griddata((x, y), z, (xic[:,None], yic[None,:]))
    #CS = plt.contour(xic,yic,zic,15,linewidths=0.5,colors='k') # Not necessary
    CS = plt.contourf(yic, xic, zic, 5, cmap = plt.cm.jet)
    plt.colorbar() # draw colorbar
    ax = plt.gca()
    ax.invert_yaxis()
    
    #plt.show()
@torch.jit.script
def key_points(heightData):
    # type: (Tensor) -> (Tensor)
   # N = 50 # Number of key points
   # probability = np.zeros(len(heightData))
    
    # Create a matrix for the sampled data
    sampled_heightData = torch.empty((20,20))
    # Create a empty vector for summing the values
    summer = torch.zeros(len(heightData[:,0]))
    # Convert numpy to torch tensor
    #data = torch.tensor(heightData)
    data = heightData
    # Get the 10% heighest points
    p = 0.1
    height_threshhold = 0.1 # cm
    height_sum_threshhold = 50 # 
    #start = time.time()
    for i in range(0, -200, -10):
        for j in range(-100, 100, 10):
            summer = torch.where((i >= data[:,0]) & (data[:,0] > i-10) & (j <= data[:,1]) & (data[:,1] < j+10), data[:,2], 0)
            if(torch.sum(summer) > height_sum_threshhold):
                pass
                # Remove points below threshhold
                B = summer[summer > height_threshhold]
                # Get number of points above threshhold
                n  = B.shape[0]
                sampled_heightData[int((abs(i))/10),int((j+100)/10)] = summer[0:int(n*p)].sum().item()/int(n*p)
            else:
                sampled_heightData[int((abs(i))/10),int((j+100)/10)] = 0

    #key_arr = np.array(random.choices(heightData, weights=probability, k=N))
    
    return sampled_heightData


# @torch.jit.script
# def key_points(heightData):
#     # type: (Tensor) -> (Tensor)
#    # N = 50 # Number of key points
#    # probability = np.zeros(len(heightData))
    
#     # Create a matrix for the sampled data
#     sampled_heightData = torch.zeros((20,20),device='cuda:0')
#     # Create a empty vector for summing the values
#     summer = torch.zeros(len(heightData[:,0]),device='cuda:0')
#     # Convert numpy to torch tensor
#     #data = torch.tensor(heightData)
#     data = heightData
#     print(data.device)
#     # Get the 10% heighest points
#     p = 0.1
#     height_threshhold = 0.1 # cm
#     height_sum_threshhold = 50 # 
#     #start = time.time()
#     a = torch.empty(1,device='cuda:0')
#     print(a.shape)
#     with torch.no_grad():
#         for i in range(0, -200, -10):
#             for j in range(-100, 100, 10):
#                 #sampled_heightData[0,0] = 0
#                 summer = torch.where((i >= data[:,0]) & (data[:,0] > i-10) & (j <= data[:,1]) & (data[:,1] < j+10), data[:,2], 0)
#                 print("o")
#                 #a = torch.sum(torch.nonzero(summer))
#                 print(torch.sum(torch.nonzero(summer).shape))
#                 if(a > height_sum_threshhold):
#                     pass
#                     # # Remove points below threshhold
#                     #B = summer[summer > height_threshhold]
#                     # # Get number of points above threshhold
#                     #n  = B.shape[0]
#                     #print(n)
#                     #print(B)
#                     #sampled_heightData[0,0] = 0
#                     #print("hej")
#                     # sampled_heightData[int((abs(i))/10),int((j+100)/10)] = summer[0:int(n*p)].sum().item()/int(n*p)
#                 else:
#                     print("o")
#                     #int((abs(i))/10)
#                     #sampled_heightData[int((abs(i))/10),int((j+100)/10)] = 0
#                 #n = torch.count_nonzero(summer)
#                 #sampled_heightData[int((abs(i))/10),int((j+100)/10)] = torch.sum(summer).item()/n
#     print(a)
#     #end = time.time()
         
#     #print(sampled_heightData)
#     #print(end-start)
def plot_pc(tf_img, img):
    ###############################################################
    # Plot camera view and top/transformed view
    scalex = [-2, 0]
    scaley = [-1, 1]


    fig1 = plt.figure()
    ax1 = fig1.gca(projection='3d')
    ax1.scatter(tf_img[:, 0], tf_img[:,1], tf_img[:,2])
    ax1.set_xlim3d(scalex)
    ax1.set_ylim3d(scaley)
    ax1.set_title('Birds view')
    ax1.set_xlabel("x axis")
    ax1.set_ylabel("y axis")
    ax1.set_zlabel("z axis")

    fig = plt.figure()
    ax = fig.gca(projection='3d')
    ax.scatter(img[:, 0], img[:,1], img[:,2])
    ax.set_xlim3d(scalex)
    ax.set_ylim3d(scaley)
    ax.set_title('Camera View')
    ax.set_xlabel("x axis")
    ax.set_ylabel("y axis")
    ax.set_zlabel("z axis")

    #plt.show() 