#from cv2 import norm
from json import load
from re import U
import pyrealsense2 as rs
import numpy as np
import math
import matplotlib.pyplot as plt
import matplotlib.rcsetup as rcsetup
from mpl_toolkits import mplot3d
from scipy.interpolate import griddata
import scipy.stats as statis
#import random
#from skimage.morphology import dilation
#from pyntcloud import PyntCloud
import torch
import time
###############################################################
# Image transformation
pipeline = rs.pipeline()
# Configure streams
config = rs.config()
config.enable_stream(rs.stream.depth, 424, 240, rs.format.z16, 30)

# Start streaming
pipeline.start(config)
x_rot = 61+180+2.3 #placed in 61 degrees than 29+90 =119, 61+90=151
y_rot = 0 #Guessed
z_rot = 2 #Guessed

omega = math.radians(x_rot)
theta = math.radians(y_rot)
kappa = math.radians(z_rot)

tx = 0 # unsure of the unit
ty = 150/100 # 
tz = 100/100 # 

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

proj = np.array([   [1, 0, 0, 0],
                    [0, 1.7666667, 0, 0],
                    [0, 0,  0, -1],
                    [0, 0, 0.16, 0]
                 ])

vinv = np.array([   [-2.1194970e-02,  9.9976873e-01, -3.6270372e-03,  0.0000000e+00],
                    [-2.7295213e-05,  3.6272737e-03,  9.9999332e-01,  0.0000000e+00],
                    [ 9.9977535e-01,  2.1194933e-02, -4.9591064e-05,  0.0000000e+00],
                    [-5.6141201e-02, -1.6406422e-03,  3.7731490e-01,  1.0000000e+00]] 
)

cameraheight = 240
camerawidth = 424


def plot_pc(tf_img, img):
    ###############################################################
    # Plot camera view and top/transformed view
    scalex = [-2, 0]
    scaley = [-1, 1]

    colors = np.random.rand(len(img[:,0]))
    colors_tf = np.random.rand(len(tf_img[:,0]))
    fig1 = plt.figure()
    ax1 = fig1.gca(projection='3d')
    ax1.scatter(tf_img[:, 0], tf_img[:,1], tf_img[:,2], c=colors_tf)
    #ax1.set_xlim3d(scalex)
    #ax1.set_ylim3d(scaley)
    ax1.set_title('Birds view')
    ax1.set_xlabel("x axis")
    ax1.set_ylabel("y axis")
    ax1.set_zlabel("z axis")
    
    fig = plt.figure()
    ax = fig.gca(projection='3d')
    ax.scatter(img[:,0], img[:,1], img[:,2], c=colors)
    #ax.set_xlim3d(scalex)
    #ax.set_ylim3d(scaley)
    ax.set_title('Camera View')
    ax.set_xlabel("x axis")
    ax.set_ylabel("y axis")
    ax.set_zlabel("z axis")
    #plt.imshow(img)
    plt.show() 

def load_pc(img):
    ###############################################################
    # Compute homography matrix and apply to input

    projection_mat = np.matmul(np.matmul(np.matmul(rotMat_x, rotMat_y), rotMat_z), trans_mat)
    tf_img = np.matmul(img,projection_mat)  
    tf_img = img.dot(projection_mat)
    tf_img = np.delete(tf_img, np.where(tf_img[:,1] < 0.05), axis=0) # Remove points closer than 0.2 meters of the robot
    tf_img = np.delete(tf_img, np.where(tf_img[:,1] > 2), axis=0)
    tf_img = np.delete(tf_img, np.where(tf_img[:,0] > 0.7), axis=0)
    tf_img = np.delete(tf_img, np.where(tf_img[:,0] < -0.7), axis=0)
    height_map(tf_img, img)
    #plot_pc(tf_img, img)

def height_map(tf_img, img):
    ##############################################################
    # Rearrange matrixes to get x, y as bird and maintain z axis from camera
    # Copy z axis from original to transformed and keep only x, y, and z axis in transform matrix
    #tf_img = np.insert(tf_img, 2, img[:,2], axis=1)
    #tf_img = np.delete(tf_img, 3, 1) # Remove transformed z values
    tf_img = np.delete(tf_img, 3, 1) # Yeet 1's

    #tf_img = tf_img[::5,:] # Poor, non generalizing down sampling
    #heightData = heightData[heightData[:,0]%5==0] # Poor generalization
    
    heightData = tf_img # Convert from meters to centimeters
    #heightData = heightData # Convert to integers
           
    x = heightData[:,0]
    y = heightData[:,1]
    z = heightData[:,2]

    # # Generalize z axis
    # h = np.where(z > 4) # Find threshold for exomy
    # for i in z:
    #     if (min(h)[0] < i) and (i < max(h)[0]):
    #         z[i] = 6
    


    ####################################
    ###### Downsample data to 20x20 grid
    # Iterate through y and then for each yi, go through all x according
    # the collective z values must for the highest half find the mean.
    # h = torch.tensor(heightData)
    # start = time.time()
    # key_arr = key_points(h)
    # end = time.time()
    #print(end-start)

    #plt.scatter(key_arr[:,1], key_arr[:,0], marker='o', s = 5, zorder = 10, color='r') # plot points on grid
    
    ##### Mapping the irregular data onto a regular grid and plotting
    xic = np.linspace(min(x), max(x), 1000)
    yic = np.linspace(min(y), max(y), 1000)
    zic = griddata((x, y), z, (xic[:,None], yic[None,:]), method='linear')
    #CS = plt.contour(xic,yic,zic,15,linewidths=0.5,colors='k') # Not necessary
    CS = plt.contourf(yic, xic, zic, 5, cmap = plt.cm.jet)
    plt.colorbar() # draw colorbar
    ax = plt.gca()
    ax.invert_yaxis()
    #ax.invert_xaxis()
    ax.set_title('Height')
    ax.set_xlabel("x axis")
    ax.set_ylabel("y axis")
    #ax.set_zlabel("z axis")
    plt.draw()

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


    
    return sampled_heightData


while True:
    # This call waits until a new coherent set of frames is available on a device
    # Calls to get_frame_data(...) and get_frame_timestamp(...) on a device will return stable values until wait_for_frames(...) is called
    points = []
    

    # Skip 5 first frames to give the Auto-Exposure time to adjust
    for x in range(5):
        pipeline.wait_for_frames()

    frames = pipeline.wait_for_frames()
    depth = frames.get_depth_frame()



    colorizer = rs.colorizer()
    colorized_depth = np.asanyarray(colorizer.colorize(depth).get_data())
    #plt.imshow(colorized_depth)



    pc = rs.pointcloud()
    #pc.map_to(color_frame);
    pointcloud = pc.calculate(depth)
    pc.map_to(depth)
    v, t = pointcloud.get_vertices(), pointcloud.get_texture_coordinates()
    verts = np.asanyarray(v).view(np.float32).reshape(-1, 3)  # xyz
    # verts = np.delete(verts, np.where(verts[:,2] < 0.1), axis=0) # Remove points closer than 0.2 meters of the robot
    # verts = np.delete(verts, np.where(verts[:,2] > 2), axis=0)
    # verts = np.delete(verts, np.where(verts[:,1] > 0.7), axis=0)
    # verts = np.delete(verts, np.where(verts[:,1] < -0.7), axis=0)
    verts = np.insert(verts, verts.shape[1], 1, axis=1) # Add 4th dimension to points
    #verts = verts[::10,:] 
    #print(np.size(verts))
    #print(verts)
    load_pc(verts)
    
    # depth_image = np.asanyarray(depth.get_data())
    # distes = np.zeros((424, 240))
    # #print(depth_image)
    # if not depth: continue
    # # Print a simple text-based representation of the image, by breaking it into 10x20 pixel regions and approximating the coverage of pixels within one meter
    # coverage = [0]*64
    # fu = 2/proj[0, 0]
    # fv = 2/proj[1, 1]
    
    # centerU = camerawidth/2
    # centerV = cameraheight/2
    
    # for y in range(240):
    #     for x in range(424):
    #         dist = depth.get_distance(x, y)
    #         #if depth_buffer[j, i] != -inf: # ignore empty space 
    #         u = -(y-centerU)/(camerawidth)  # image-space coordinate
    #         v = (x-centerV)/(cameraheight)  # image-space coordinate
    #         d = dist # depth buffer value
    #         X2 = [d*u, d*v, d, 1]  # deprojection vector
    #         p2 = np.asarray(X2*vinv)  # Inverse camera view to get world coordinates
    #         points.append([p2[0, 0], p2[0, 1], p2[0, 2]])

    # print(points)
    # #pcd.points = o3d.utility.Vector3dVector(np.array(points))
    # out = np.asarray(points) #np.asarray(pcd.points)
    # # print(points)
    # # m,n = distes.shape
    # # R,C = np.mgrid[:m,:n]
    # # print(distes)
    # # out = np.column_stack((C.ravel(),R.ravel(), distes.ravel()))
    # out = np.delete(out, np.where(out[:,0] < -200), axis=0) # remove all points farther than 2 meters in front of robot
    # out = np.insert(out, out.shape[1], 1, axis=1) # Add 4th dimension to points
    # #print(out)
    # plt.imshow(depth_image)
    plt.show()
    # load_pc(out)
exit(0)
