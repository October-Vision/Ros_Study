#include "ros/ros.h"
#include "com_test/haha.h"

int main(int argc,char *argv[]){
    ros::init(argc,argv,"haha_use");
    hello_ns::My my;
    my.run();
    return 0;
}