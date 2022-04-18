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
from sensor_msgs_py import point_cloud2
sys.path.append('/home/xavier/ExoMy_Software/exomy/scripts/utils')
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
        self.ActionSub = self.create_subscription(
            PointCloud2,
            '/camera/depth/color/points',
            self.callback,
            10)


        """Init Camera."""
        self.camera = Cameras()
        self.get_logger().info('\t{} STARTED.'.format(self.node_name.upper()))
      
        
        

    def callback(self, data):
        #print("hello")
        pc = np.asarray(point_cloud2.read_points_list(data))
        pc = tf_img = np.delete(pc, 3, 1)
        pc = np.insert(pc, pc.shape[1], 1, axis=1)
        #self.get_logger().info('\tPC point: {}'.format(pc[0]))
        points, Robotpos, RobotVel, RobotAcc, rot, ang_vel, ang_acc  = self.camera.callback(pc)
        

        dataMsg = CameraData()
        dataMsg.robot_pos = Robotpos
        dataMsg.robot_vel = RobotVel
        dataMsg.robot_acc = RobotAcc
        self.pub.publish(dataMsg)

        self.get_logger().info('\tRobot Rotation: {}'.format(rot))
        self.get_logger().info('\tRobot Angular Velocity: {}'.format(ang_vel))
        self.get_logger().info('\tRobot Angular Acceleration: {}'.format(ang_acc))
        PointCloudTrans = PointCloud()
        for i in range(len(points)):
            point = Point32()
            point.x = float(points[i][0])
            point.y = float(points[i][1])
            point.z = float(points[i][2])
            PointCloudTrans.points.append(point)
        PointCloudTrans.header = data.header
        self.pointpub.publish(PointCloudTrans)
        #self.get_logger().info('\tMin: {}'.format(min(points[:,2])))
        #self.get_logger().info('\tMax: {}'.format(max(points[:,2])))


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