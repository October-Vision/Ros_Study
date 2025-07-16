/*
    参数服务器操作之新增与修改(二者API一样)_C++实现:
    在 roscpp 中提供了两套 API 实现参数操作
    ros::NodeHandle
        setParam("键",值)
    ros::param
        set("键","值")

    示例:分别设置整形、浮点、字符串、bool、列表、字典等类型参数
        修改(相同的键，不同的值)

*/
#include "ros/ros.h"
#include<iostream>
#include<string>
int main(int argc,char *argv[]){
    ros::init(argc,argv,"update_Param");
    std::vector<std::string> stus;
    stus.push_back("zhangsan");
    stus.push_back("王者荣誉");
    stus.push_back("和平精英");

    std::map<std::string,std::string> friends;
    friends["guo"]="huang";
    friends["yuang"]="xiao";

    //NodeHandle
    ros::NodeHandle nh;
    nh.setParam("nh_int",10);//整形
    nh.setParam("nh_double",3.14);//浮点型
    nh.setParam("nh_bool",true);//bool型
    nh.setParam("nh_string","hello NodeHandle");//字符串
    nh.setParam("nh_vector",stus);
    nh.setParam("nh_map",friends);
    int value1=0;
    nh.getParam("nh_int",value1);
    ROS_INFO("修改前的值为：%d",value1);

    //修改演示

    nh.setParam("nh_int",10000);
    int value=0;
    nh.getParam("nh_int",value);
    ROS_INFO("修改后的值是:%d",value);
    //param
    ros::param::set("param_int",20);
    ros::param::set("param_double",3.14);
    ros::param::set("param_bool",false);
    ros::param::set("param_vector",stus);
    ros::param::set("param_map",friends);
    ros::param::set("param_string","wnag");

    //修改演示（相同的键，不同的值）

    ros::param::set("param_int",20000);
    return 0;
}