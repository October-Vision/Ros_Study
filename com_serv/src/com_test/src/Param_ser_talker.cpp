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
    friends["guo"]="huang"
    friends["yuang"]="xiao"
}