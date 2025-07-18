/*
    需求: 实现基本的话题通信，一方发布数据，一方接收数据，
         实现的关键点:
         1.发送方
         2.接收方
         3.数据(此处为普通文本)


    消息订阅方:
        订阅话题并打印接收到的消息

    实现流程:
        1.包含头文件 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 订阅者 对象
        5.处理订阅的消息(回调函数)
        6.设置循环调用回调函数

*/

#include "ros/ros.h"
#include "std_msgs/String.h"

void DoMsg(const std_msgs::String::ConstPtr& msg_p){
    ROS_INFO("收到:%s",msg_p ->data.c_str());
}

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"listen");
    ros::NodeHandle nh;
    //实例化订阅者对象
    ros::Subscriber sub=nh.subscribe <std_msgs::String> ("chatter",10,DoMsg);//回调处理数据
    ros::spin();
    return 0;
}