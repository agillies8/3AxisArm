#!/usr/bin/env python
 
import rospy

from std_msgs.msg import String, Int16MultiArray
from geometry_msgs.msg import Twist

class ArmCommander:
    def __init__(self):
        # init ros
        rospy.init_node('Arm_Commander', anonymous=True)
        sub = rospy.Subscriber('cmd_vel', Twist, self.get_cmd_vel, queue_size=1)
        self.pub = rospy.Publisher('axis_commands', Int16MultiArray, queue_size=1)
        self.command_arm()

# get cmd_vel message from ROS, and get linear velocity and angular velocity
    def get_cmd_vel(self, data):
        x = data.linear.x
        y=data.linear.y
        angular = data.angular.z
        self.send_cmd_to_arduino(x, y, angular)

    # translate x, and angular velocity to PWM signal of each wheels, and send to arduino
    def send_cmd_to_arduino(self, x, y, angular):
        # decode the cmd_vels
        axis_command= Int16MultiArray()
        axis_command.data = [0,0,0,0,0,0]
        if x > 0:
            axis_command.data[0] = 1
            axis_command.data[1] = 0
        elif x < 0:
            axis_command.data[0] = 1
            axis_command.data[1] = 1
        else:
            axis_command.data[0] = 0
            axis_command.data[1] = 0
            
        # publish to topic that arduino will read
        rospy.loginfo(axis_command)
        self.pub.publish(axis_command)

    # receive serial text from arduino and publish it to '/arduino' message
    def command_arm(self):
        pub = rospy.Publisher('arduino', String, queue_size=1)
        r = rospy.Rate(100)
        while not rospy.is_shutdown():
            r.sleep()

if __name__ == '__main__':
    try:
        a = ArmCommander()
    except rospy.ROSInterruptException: 
        pass