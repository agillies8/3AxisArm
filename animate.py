#!/usr/bin/env python
 
import rospy

from std_msgs.msg import String
from geometry_msgs.msg import Twist, Point

def commandEyes(msg):
    x = msg.linear.x
    y = msg.linear.y
    z=msg.angular.z
    pt = Point(x = z, y = x, z=y)
    pub.publish(pt)

if __name__=='__main__':
    rospy.init_node('eye_animator')
   
    sub = rospy.Subscriber('cmd_vel', Twist, commandEyes, queue_size=1)    
    pub = rospy.Publisher('eyePos', Point, queue_size=1)
    rate=rospy.Rate(10)
 
    while not rospy.is_shutdown():
        rate.sleep()