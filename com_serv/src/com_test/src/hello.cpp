#include "ros/ros.h"
#include "com_test/hello.h"

namespace hello_ns{
    void Hellopub::run(){
        ROS_INFO("头文件的调用");
    }
}

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"test_head_node");
    hello_ns::Hellopub hello;
    hello.run();
    return 0;
}