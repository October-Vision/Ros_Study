#! /usr/bin/env python

"""
    需求: 
        编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器
        服务器需要解析客户端提交的数据，相加后，将结果响应回客户端，
        客户端再解析

    客户端实现:
        1.导包
        2.初始化 ROS 节点
        3.创建请求对象
        4.发送请求
        5.接收并处理响应

    优化:
        加入数据的动态获取


"""

import rospy
from com_test.srv import ADDsum,ADDsumRequest,ADDsumResponse
import sys

if __name__=="__main__":
    if len(sys.argv)!=3:
        rospy.logerr("参数错误")
        sys.exit(1)
    
    rospy.init_node("srv_client")
    client =rospy.ServiceProxy("ADDsum_py",ADDsum)
    #请求前等待服务就绪
    #方式1:
    rospy.wait_for_service("ADDsum_py")
    #方式2
    #client.wait_for_service()
    #发送请求
    #方式1:
    #resp =client(3,4)
    #方式2：
    #resp = client(ADDsumRequest(1,5))
    #方式3：
    req=ADDsumRequest()
    #req.num1=100
    #req.num2=200

    #优化
    req.num1 =int(sys.argv[1])
    req.num2 =int(sys.argv[2])

    resp=client.call(req)
    rospy.loginfo("响应结果为:%d",resp.sum)
