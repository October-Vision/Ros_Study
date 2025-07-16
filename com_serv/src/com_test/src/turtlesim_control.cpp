/*
消息类型
geometry_msgs/Vector3 linear
  float64 x
  float64 y
  float64 z
geometry_msgs/Vector3 angular
  float64 x
  float64 y
  float64 z
linear(线速度) 下的xyz分别对应在x、y和z方向上的速度(单位是 m/s)；

angular(角速度)下的xyz分别对应x轴上的翻滚、y轴上俯仰和z轴上偏航的速度(单位是rad/s)。

节点信息：
/rosout
/rosout_agg
/statistics
/turtle1/cmd_vel
/turtle1/color_sensor
/turtle1/pose


准备工作:
        1.获取topic(已知: /turtle1/cmd_vel)
        2.获取消息类型(已知: geometry_msgs/Twist)
        3.运行前，注意先启动 turtlesim_node 节点

实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建发布者对象
        4.循环发布运动控制消息
*/

#include "ros/ros.h"

#include "geometry_msgs/Twist.h"

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"control_turtlesim");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise <geometry_msgs::Twist>("/turtle1/cmd_vel",1000);

    geometry_msgs::Twist msg;

    msg.linear.x=1.0;
    msg.linear.y=0.0;
    msg.linear.z=0.0;

    msg.angular.x=0.0;
    msg.angular.y=0.0;
    msg.angular.z=2.0;

    ros::Rate r(10);
    while (ros::ok())
    {   if(msg.linear.x<10)
        {
            msg.linear.x+=1;
            msg.linear.y+=1;
            msg.linear.z+=1;
            
            msg.angular.x +=1;
        }else{
            msg.linear.x =0;
            msg.angular.x =0;
        }
        pub.publish(msg);

        ros::spinOnce();
    }
    return 0;
}