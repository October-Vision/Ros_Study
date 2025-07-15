import rospy
if __name__=="__main__":
    rospy.init_node("Hello_py")
    while True:
        rospy.loginfo("hello python")