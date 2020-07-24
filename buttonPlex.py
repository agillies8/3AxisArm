#!/usr/bin/env python
 
import rospy

from std_msgs.msg import String, Int32
 
b1_val=0
b2_val=0

def btn1_callback(msg):
    global b1_val
    btn1=msg.data
    if btn1 =="NOT pressed":
        b1_val = 0
    else:
        rospy.loginfo('Button 1 was pressed with following message: ' +  msg.data)
        b1_val  = 1
        

def btn2_callback(msg):
    global b2_val
    btn2=msg.data
    if btn2 =="NOT pressed":
        b2_val = 0
    else:
        rospy.loginfo('Button 1 was pressed with following message: ' + msg.data)
        b2_val  = 1
   
if __name__=='__main__':
    rospy.init_node('Button_multiplex')
   
    sub1=rospy.Subscriber('button_press_1', String, btn1_callback)
    sub2=rospy.Subscriber('button_press_2', String, btn2_callback)


    pub=rospy.Publisher('button_counter', Int32, queue_size=1)
    rate=rospy.Rate(10)
 
    while not rospy.is_shutdown():
        buttons_total = b1_val+b2_val
        pub.publish(buttons_total)
        rate.sleep()