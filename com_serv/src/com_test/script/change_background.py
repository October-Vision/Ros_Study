import rospy

if __name__ =="__main__":
    rospy.init_node("change_bk_py")

    rospy.set_param("background_r",255)
    rospy.set_param("background_g",255)
    rospy.set_param("background_b",255)