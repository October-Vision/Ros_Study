/*  
    订阅小乌龟的位姿: 时时获取小乌龟在窗体中的坐标并打印
    准备工作:
        1.获取话题名称 /turtle1/pose
        2.获取消息类型 turtlesim/Pose
        3.运行前启动 turtlesim_node 与 turtle_teleop_key 节点

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建订阅者对象
        5.回调函数处理订阅的数据
        6.spin
        float32 x
float32 y
float32 theta
float32 linear_velocity
float32 angular_velocity

*/
#include "ros/ros.h"

#include "turtlesim/Pose.h"

void DoMsg(const turtlesim::Pose::ConstPtr& p){
    ROS_INFO("乌龟位姿信息:x=%.2f,y=%.2f,theya=%.2f,lv=%.2f,av=%.2f",
    p->x,p->y,p->theta,p->linear_velocity,p->angular_velocity);
}

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub_pose");

    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe<turtlesim::Pose>("/turtle1/pose",1000,DoMsg);

    ros::spin();
    return 0;
}