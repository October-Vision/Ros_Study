import rospy

from turtlesim.msg import Pose

def Domsg(date):
    rospy.loginfo("乌龟坐标:x=%.2f,y=%.2f,姿态信息:theta=%.2f",
                  date.x,date.y,date.theta)

if __name__=="__main__":
    rospy.init_node("sub_pose_py")
    sub=rospy.Subscriber("/turtle1/pose",Pose,Domsg,queue_size=1000)

    rospy.spin()