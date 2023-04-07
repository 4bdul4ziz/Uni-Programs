import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan


class ObstacleAvoidance(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance')
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.laser_sub = self.create_subscription(LaserScan, '/scan', self.laser_callback, 10)

    def laser_callback(self, msg):
        ranges = msg.ranges
        front_angles = [-30, -15, 0, 15, 30]
        front_ranges = [ranges[int(angle/0.25)] for angle in front_angles]
        min_range = min(front_ranges)
        min_index = front_ranges.index(min_range)
        angle = front_angles[min_index]
        self.avoid_obstacle(angle, min_range)

    def avoid_obstacle(self, angle, min_range):
        if min_range < 0.5:
            if angle > 0:
                steer_angle = -1.0
            else:
                steer_angle = 1.0
            speed = 0.1
        else:
            steer_angle = 0.0
            speed = 0.2

        twist = Twist()
        twist.linear.x = speed
        twist.angular.z = steer_angle
        self.cmd_vel_pub.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance = ObstacleAvoidance()
    rclpy.spin(obstacle_avoidance)
    obstacle_avoidance.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
