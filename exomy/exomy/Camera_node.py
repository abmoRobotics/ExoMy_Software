import rclpy
from rclpy.node import Node
from rclpy.timer import Timer
from exomy_msgs.msg import CameraData
import numpy as np
import time
class Camera_node(Node):
    """Convert Motor Commands"""

    def __init__(self):
        """Init Node."""
        self.node_name = 'Camera_node'
        super().__init__(self.node_name)

        # Create publisher
        self.pub = self.create_publisher(
            CameraData,
            'CameraData',
            1)

        self.get_logger().info('\t{} STARTED.'.format(self.node_name.upper()))
        self.run()
        

    def __del__(self):
        pass

    def run(self):
        while(1):
            message = CameraData()

            message.depth_data = [0.0, 0.0]
            message.tracking_data = [0.0, 0.0]
            self.pub.publish(message)
            time.sleep(3)


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