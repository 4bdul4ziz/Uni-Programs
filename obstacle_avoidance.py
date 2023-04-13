#!/usr/bin/env python

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

class ObstacleDetection(Node):

    def __init__(self):
        super().__init__('obstacle_detection_node')

        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.sub = self.create_subscription(LaserScan, '/scan', self.callback, 10)

    def callback(self, msg):
        move = Twist()

        # Laser scan range threshold
        thr1 = 0.8
        thr2 = 0.8

        if msg.ranges[0] > thr1 and msg.ranges[15] > thr2 and msg.ranges[345] > thr2:
            # No obstacles ahead, move forward
            move.linear.x = 0.5
            move.angular.z = 0.0
        else:
            # Obstacle detected, stop and rotate
            move.linear.x = 0.0
            move.angular.z = 0.5

        self.pub.publish(move)

def main(args=None):
    rclpy.init(args=args)
    node = ObstacleDetection()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
