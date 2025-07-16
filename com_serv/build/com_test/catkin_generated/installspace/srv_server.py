#!/usr/bin/env python3

"""
    需求: 
        编写两个节点实现服务通信，客户端节点需要提交两个整数到服务器
        服务器需要解析客户端提交的数据，相加后，将结果响应回客户端，
        客户端再解析

    服务器端实现:
        1.导包
        2.初始化 ROS 节点
        3.创建服务对象
        4.回调函数处理请求并产生响应
        5.spin 函数

"""

import rospy
from com_test.srv import ADDsum,ADDsumRequest,ADDsumResponse

def doReq(req):
    sum=req.num1+req.num2
    rospy.loginfo("提交的数据为:num1=%d和num2=%d",req.num1,req.num2)

    #创建响应对象，赋值并返回
    #resp=ADDsumResponse()
    #resp.sum=sum
    resp=ADDsumResponse(sum)
    return resp

if __name__=="__main__":
    rospy.init_node("py_srv_server")

    server=rospy.Service("ADDsum_py",ADDsum,doReq)

    rospy.spin()
