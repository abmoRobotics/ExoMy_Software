#!/usr/bin/env python
import rclpy
from rclpy.node import Node
from rclpy.timer import Timer
from exomy_msgs.msg import CameraData
from sensor_msgs.msg import PointCloud2, PointCloud
from std_msgs.msg import Header
from builtin_interfaces.msg import Time
from geometry_msgs.msg import Point32
import numpy as np
import time
import sys
import torch
import message_filters
#from sensor_msgs_py import point_cloud2
sys.path.append('/home/xavier/ExoMy_Software/exomy/scripts/utils')
sys.path.append('/home/xavier/ros2_numpy')
import ros2_numpy
from CameraSys import Cameras
class Camera_node(Node):
    """Convert Motor Commands"""

    def __init__(self):
        

        
        
        

        """Init Node."""
        self.node_name = 'Camera_node'
        super().__init__(self.node_name)
        self.pub = self.create_publisher(
                CameraData,
                'CameraData',
                1)
        self.pointpub = self.create_publisher(
                PointCloud,
                'pointcloud',
                1)
        self.Keypointpub = self.create_publisher(
                PointCloud,
                'Keypoint',
                1)

        self.cam1Sub = message_filters.Subscriber(self, PointCloud2, "/cam_1/depth/color/points")
        self.cam2Sub = message_filters.Subscriber(self, PointCloud2, "/cam_2/depth/color/points")

        queue_size = 1
        self.ts = message_filters.ApproximateTimeSynchronizer([self.cam1Sub, self.cam2Sub], queue_size, 0.8)
        self.ts.registerCallback(self.callback)


        # self.ActionSub = self.create_subscription(
        #     PointCloud2,
        #     '/camera/depth/color/points',
        #     self.callback,
        #     10)


        """Init Camera."""
        self.camera = Cameras()
        
        self.get_logger().info('\t{} STARTED.'.format(self.node_name.upper()))
      
        
       

    def callback(self, data_cam1, data_cam2):
        #print("hello")
        try:
            start = time.perf_counter()
            #pc = np.asarray(point_cloud2.read_points_list(data))
            #pc = np.asarray(self.camera.read_points_list(data))
            pc1 = ros2_numpy.numpify(data_cam1)
            pc2 = ros2_numpy.numpify(data_cam2)

            points=np.zeros((pc1.shape[0],3))
            points[:,0]=pc1['x']
            points[:,1]=pc1['y']
            points[:,2]=pc1['z']
            pcnp = np.array(points, dtype=np.float32)
            
            points2=np.zeros((pc2.shape[0],3))
            points2[:,0]=pc2['x']
            points2[:,1]=pc2['y']
            points2[:,2]=pc2['z']
            pcnp2 = np.array(points2, dtype=np.float32)
            #pc2 = np.array(ros2_numpy.numpify(data_cam2).tolist())
            #self.get_logger().info('\tPointcloud2: {}'.format(pc2))
            #pc = np.delete(pc, 3, 1)
            #self.get_logger().info('\tPC: {}'.format(pc))
            pcnp = np.insert(pcnp, pcnp.shape[1], 1, axis=1)
            pcnp2 = np.insert(pcnp2, pcnp2.shape[1], 1, axis=1)
            #self.get_logger().info('\tPointcloud1: {}'.format(pcnp))
            
            #points, Robotpos, RobotVel, RobotAcc, RobotRot, ang_vel, ang_acc, elaps  = self.camera.callback(pcnp)
            points, Robotpos, RobotVel, RobotAcc, RobotRot, ang_vel, ang_acc, keypoints, elaps  = self.camera.callback(pcnp, pcnp2)
            
            #self.get_logger().info('\tSize of array: {}'.format(sum_cloud.shape))
            
            dataMsg = CameraData()
            dataMsg.robot_pos = Robotpos.tolist()
            dataMsg.robot_vel = RobotVel.tolist()
            dataMsg.robot_acc = RobotAcc.tolist()
            dataMsg.robot_rot = RobotRot.tolist()
            
            #self.get_logger().info('\tTime 2: {}'.format(time.perf_counter() - start))
            #detach keypoints from tensor to numpy
            
            keypoints = keypoints.cpu().detach().numpy()
            
            #remove x and y values from height map
            #self.get_logger().info('\tPos 1: {}'.format(Robotpos))
            #self.get_logger().info('\tType: {}'.format(keypoints))
            #self.get_logger().info('\tType: {}'.format(keypoints))
            
            #self.get_logger().info('\tKeyPoints: {}'.format(keypoints))
            #self.get_logger().info('\tRobot Rotation: {}'.format(RobotRot))
            #self.get_logger().info('\tRobot Angular Velocity: {}'.format(ang_vel))
            #self.get_logger().info('\tRobot Angular Acceleration: {}'.format(ang_acc))
            
            # PointCloudTrans = PointCloud()
            # for i in range(len(points)):
            #     point = Point32()
            #     point.x = float(points[i][0])
            #     point.y = float(points[i][1])
            #     point.z = float(points[i][2])
            #     PointCloudTrans.points.append(point)
            # PointCloudTrans.header = data_cam1.header
            # self.pointpub.publish(PointCloudTrans)
            #dataMsg.depth_data = keypoints.cpu().detach().numpy()
            
            #self.get_logger().info('\tTime 3: {}'.format(time.perf_counter() - start))
            #self.get_logger().info('\tTime: {}'.format(elaps))
            
            
            #keypoints_np = keypoints.cpu().detach().numpy()
            # SampledPointCloudTrans = PointCloud()
            # for data_point in keypoints:
            #     point = Point32()
            #     point.x = float(data_point[0])
            #     point.y = float(data_point[1])
            #     point.z = float(data_point[2])
            #     SampledPointCloudTrans.points.append(point)

            # SampledPointCloudTrans.header = data_cam1.header
            # self.Keypointpub.publish(SampledPointCloudTrans)
            
            # for i in range(20):
            #     y = i/10
            #     y = -y
            #     for j in range(20):
            #         x = j/10    # Convert to meter (0-2m)
            #         x = x - 1
            #         point = Point32()
            #         point.x = float(x)
            #         point.y = float(y)
            #         point.z = float(keypoints_np[j][i])
            #         SampledPointCloudTrans.points.append(point)
            
            
            keypoints = np.delete(keypoints, 0, 1)
            keypoints = np.delete(keypoints, 0, 1)
            
            keypoints = keypoints.flatten().tolist()
            #self.get_logger().info('\tTime 1: {}'.format(time.perf_counter() - start))
            #self.get_logger().info('\tKeyPoints: {}'.format(keypoints))
            
            dataMsg.depth_data = keypoints
            self.pub.publish(dataMsg)
            #self.get_logger().info('\tMin: {}'.format(min(points[:,2])))
            #self.get_logger().info('\tMax: {}'.format(max(points[:,2])))
            #exit()
            #self.get_logger().info('\tTime: {}'.format(time.perf_counter() - start))
        except Exception as e: 
           self.get_logger().info('\tERROR: {}'.format(e))

def main(args=None):
    rclpy.init(args=args)

    try:
        CameraNode = Camera_node()
        try:
            rclpy.spin(CameraNode)
        finally:
            CameraNode.destroy_node()
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()



if __name__ == '__main__':
    main()