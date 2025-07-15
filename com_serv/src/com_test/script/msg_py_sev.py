import rospy
from com_test.msg import Person

is_first_msg=True

def doPerson(p):
    global is_first_msg
    if is_first_msg:
        rospy.loginfo("收到消息")
        is_first_msg=False
    
    rospy.loginfo("收到，姓名:%s,年龄:%d,身高：%.2f",p.name,p.age,p.height)

if __name__=="__main__":
    rospy.init_node("msg_listen_person")
    rospy.loginfo("节点已经启动，等待消息")
    sub =rospy.Subscriber("Person_msg",Person,doPerson,queue_size=10)
    rospy.spin()
