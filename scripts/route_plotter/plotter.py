import numpy as np
import math
import matplotlib.pyplot as plt
import csv

def Plot(EnvPic, PosLog, MotorLog, InitialCoord, InitialRot):
    
    PosData = []
    MotorData = []

    # Load PosLog CSV File
    with open(PosLog, 'r') as csvfile:
        # creating a csv reader object
        csvreader = csv.reader(csvfile)
        # extracting each data row one by one
        for row in csvreader:
            PosData.append(row)
        # get total number of rows
        print("No. of position datapoints: %d"%(csvreader.line_num))
    #Convert to numpy
    npPosData = np.array(PosData , dtype=np.float32)

    # Load MotorLog CSV File
    with open(MotorLog, 'r') as csvfile:
        # creating a csv reader object
        csvreader = csv.reader(csvfile)
        # extracting each data row one by one
        for row in csvreader:
            MotorData.append(row)
        # get total number of rows
        print("No. of Motor datapoints: %d"%(csvreader.line_num))
    #Convert to numpy
    npMotorData = np.array(MotorData , dtype=np.float32)

    plt.rcParams["figure.figsize"] = [7.00, 8.00]
    plt.rcParams["figure.autolayout"] = True
    
    # Plot route on picture
    ax1 = plt.subplot(311)
    im = plt.imread(EnvPic)
    im = ax1.imshow(im, extent=[0, EnvSize[0], 0, EnvSize[1]])
    x_scaled = (npPosData[:,0])*1000
    y_scaled = (npPosData[:,1])*1000
    q = InitialRot
    x = x_scaled*math.cos(q) - y_scaled*math.sin(q)
    y = x_scaled*math.sin(q) + y_scaled*math.cos(q)
    x_shifed = x + InitialCoord[0]*1000
    y_shifed = y + InitialCoord[1]*1000
    ax1.plot(x_shifed, y_shifed, ls='--', linewidth=2, color='red')

    ax2 = plt.subplot(312)
    ax2.plot(npMotorData[:, 0], ls='-', linewidth=2, color='red', label='S0')
    ax2.plot(npMotorData[:, 1], ls='-', linewidth=2, color='blue', label='S1')
    ax2.plot(npMotorData[:, 2], ls='-', linewidth=2, color='green', label='S2')
    ax2.plot(npMotorData[:, 3], ls='-', linewidth=2, color='plum', label='S3')
    ax2.plot(npMotorData[:, 4], ls='-', linewidth=2, color='purple', label='S4')
    ax2.plot(npMotorData[:, 5], ls='-', linewidth=2, color='brown', label='S5')
    ax2.legend()

    ax3 = plt.subplot(313)
    ax3.plot(npMotorData[:, 6], ls='-', linewidth=2, color='pink', label='D0')
    ax3.plot(npMotorData[:, 7], ls='-', linewidth=2, color='olive', label='D1')
    ax3.plot(npMotorData[:, 8], ls='-', linewidth=2, color='cyan', label='D2')
    ax3.plot(npMotorData[:, 9], ls='-', linewidth=2, color='yellow', label='D3')
    ax3.plot(npMotorData[:, 10], ls='-', linewidth=2, color='orange', label='D4')
    ax3.plot(npMotorData[:, 11], ls='-', linewidth=2, color='grey', label='D5')
    ax3.legend()

    plt.show()

if __name__ == "__main__":

    StartCoord = [0.6,2]
    StartRot = 0.9 #Zero is along X-axis - radians
    EnvSize = [4000, 2440] #X,Y - mm

    Plot("Sandkasse.jpg", "Position.csv", "MotorCommands.csv", StartCoord, StartRot)