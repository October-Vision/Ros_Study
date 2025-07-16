import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse

if __name__=="__main__":
    rospy.init_node("py_crete_curtlr_srv")

    client = rospy.ServiceProxy("/spawn",Spawn)

    client.wait_for_service()

    req=SpawnRequest()

    req.x=2.0
    req.y=1.0
    req.theta=1.5
    req.name="wang_py"

    try:
        responde=client.call(req)
        rospy.loginfo("创建成功")
    except rospy.ServiceException as e:
        rospy.loginfo("error")