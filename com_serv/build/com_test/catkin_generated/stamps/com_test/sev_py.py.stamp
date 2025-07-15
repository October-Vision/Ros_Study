#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def DoMsg(msg):
    rospy.loginfo("收到的数据为:%s",msg.data)

if __name__=="__main__":
    rospy.init_node("sub_py")
    sub=rospy.Subscriber("py_hello",String,DoMsg,queue_size=10)

    rospy.spin()