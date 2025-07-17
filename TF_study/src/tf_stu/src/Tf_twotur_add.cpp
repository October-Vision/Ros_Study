/*
实现分析:

乌龟跟随实现的核心，是乌龟A和B都要发布相对世界坐标系的坐标信息，然后，订阅到该信息需要转换获取A相对于B坐标系的信息，最后，再生成速度信息，并控制B运动。

启动乌龟显示节点
在乌龟显示窗体中生成一只新的乌龟(需要使用服务)
编写两只乌龟发布坐标信息的节点
编写订阅节点订阅坐标信息并生成新的相对关系生成速度信息
实现流程:C++ 与 Python 实现流程一致

新建功能包，添加依赖

编写服务客户端，用于生成一只新的乌龟

编写发布方，发布两只乌龟的坐标信息

编写订阅方，订阅两只乌龟信息，生成速度信息并发布

运行*/
#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"two_turtle");

    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    ros::service::waitForService("/spawn");

    turtlesim::Spawn srv;
    srv.request.name= "turtle2";
    srv.request.x=1.0;
    srv.request.y=2.0;
    srv.request.theta=3.12415926;

    bool flog=client.call(srv);

    if(flog){
        ROS_INFO("生成乌龟成功，乌龟名称:%s",srv.response.name.c_str());
    }else{
        ROS_ERROR("生成乌龟失败");
    }

    ros::spin();
    return 0;
}
