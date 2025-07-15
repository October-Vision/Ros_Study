import rospy
from com_test.msg import Person

if __name__=="__main__":
    rospy.init_node("py_talker_msg")
    pub=rospy.Publisher("Person_msg",Person,queue_size=10)
    p = Person()
    p.name="王者荣耀"
    p.age=18
    p.height=12.0

    rate=rospy.Rate(1)
    while not rospy.is_shutdown():
        pub.publish(p)
        rate.sleep()
        rospy.loginfo("姓名:%s,年龄：%d身高:%.2f",p.name,p.age,p.height)