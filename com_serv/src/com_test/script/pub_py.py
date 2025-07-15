#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

if __name__=="__main__":
    rospy.init_node("talker_py")
    pub=rospy.Publisher("py_hello",String,queue_size=10)
    pub2=rospy.Publisher("chatter",String,queue_size=10)

    msg=String()
    msg_front = "hello 你好我是"
    count=0
    rate= rospy.Rate(1)

    while not rospy.is_shutdown():
        msg.data=msg_front+str(count)

        pub.publish(msg)
        pub2.publish(msg)
        rate.sleep()

        rospy.loginfo("写出的数据:%s",msg.data)

        count+=1