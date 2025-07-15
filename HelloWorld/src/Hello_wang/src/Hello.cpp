#include "ros/ros.h"

int main(int argc, char *argv[]){
    ros::init(argc,argv,"hello_wps");
    ros::NodeHandle n;
    while (true)
    {
      ROS_INFO("hallo!");

    };
    ros::spin();
    return 0;
    // setlocale(LC_ALL,"");
    // //执行节点初始化
    // ros::init(argc,argv,"HelloVSCode");

    // //输出日志
    // ROS_INFO("Hello VSCode!!!哈哈哈哈哈哈哈哈哈哈");
    // return 0;
}