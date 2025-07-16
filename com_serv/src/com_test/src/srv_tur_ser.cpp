/*
srv类型：

float32 x
float32 y
float32 theta
string name
---
string name
*/

#include "ros/ros.h"

#include "turtlesim/Spawn.h"

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"set_turtle");
    ros::NodeHandle nh;
    ros::ServiceClient client =nh.serviceClient<turtlesim::Spawn>("/spawn");

    ros::service::waitForService("/spawn");

    turtlesim::Spawn spawn;
    std::string input;
    while (ros::ok())
    {
        std::cout<<"请输入参数 x y theta name"<<std::endl;
        std::getline(std::cin,input);
        if(input=="q" || input=="Q"){
            break;
        }
        std::istringstream iss(input);
        double x,y,theta;
        std::string name;
        if(iss>>x>>y>>theta>>name){
            spawn.request.x=x;
            spawn.request.y=y;
            spawn.request.theta=theta;
            spawn.request.name= name;
            bool  flag=client.call(spawn);
            if (flag)
                {
                    ROS_INFO("新的乌龟生成,名字:%s",spawn.response.name.c_str());
                } else {
                    ROS_INFO("乌龟生成失败！！！");
                        }
        }
        //ros::spin();
    }
    

    return 0;
}