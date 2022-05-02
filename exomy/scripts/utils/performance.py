import timeit
#from Camerasys import key_points
import torch
import numpy as np

def setup(): 
    return np.random.rand(100000,3)

def heightmap_distribution1(delta=0.1, front_heavy=0.0, limit=1.2):

    point_distribution = []

    # If delta variable not set, exit.
    if delta == 0.0:
        print("Need delta value!")
        exit()

    y = 0.296
    while y < limit:
        
        x = 0.0

        delta += front_heavy

        while x < limit_x(y):
            
            if x == 0.0:
                point_distribution.append([-x, -y])
            else:
                point_distribution.append([-x, -y])
                point_distribution.append([x, -y])
            
            x += delta

        y += delta

    point_distribution = np.round(point_distribution, 4)


    return point_distribution
def limit_x(x):
    return x*(0.24555/0.296)+0.13338

#@torch.jit.script
def function(heightData,h):
    # type: (Tensor, Tensor) -> (Tensor)
    device = torch.device('cuda:0')
    # N = 50 # Number of key points
    # probability = np.zeros(len(heightData))
    heightmap_distribution = h
    # Create a matrix for the sampled data
    sampled_heightData = torch.empty((heightmap_distribution.shape[0],3), device = device)
    # Create a empty vector for summing the values
    summer = torch.zeros(heightData[:,0].shape[0], device=device)
    # Convert numpy to torch tensor
    data = heightData.to(device)
    # Get the 10% heighest points
    p = 1
    height_threshhold = 0.001 # cm
    height_sum_threshhold = 0.5 # 
    zeros = torch.zeros(data.shape[0],device=device)
    sampled_heightData[:,0] = heightmap_distribution[:,0]
    sampled_heightData[:,1] = heightmap_distribution[:,1]

    # sampled_heightData[:,2] = heightmap_distribution[:,0]
    for i, point in enumerate(heightmap_distribution):
        x = point[0]
        y = point[1]
        summer = data[:,2][((x+0.05 >= data[:,0]) & (data[:,0] > x-0.05) & (y-0.05 <= data[:,1]) & (data[:,1] < y+0.05))]#, data[:,2], zeros)
        try:
            sampled_heightData[i,2] = summer.sum().item()/int(summer.shape[0]*p)
        except:
            pass
    return sampled_heightData

if __name__ == "__main__":
    import time
    data=torch.randn(1000000,3)
    h = heightmap_distribution1( delta=0.1, limit=1.2,front_heavy=0.0)

    h = torch.from_numpy(h)
    function(data,h)
    function(data,h)
    function(data,h)
    function(data,h)
    function(data,h)
    function(data,h)
    function(data,h)
    function(data,h)
    function(data,h)
    function(data,h)
    function(data,h)
    
    start_time =time.time()
    #torch.jit.trace(function,(data,h))
    function(data,h)
    end_time = time.time()
    print(end_time-start_time)