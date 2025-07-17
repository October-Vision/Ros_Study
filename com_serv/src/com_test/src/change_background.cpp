/*
/rosdistro
/roslaunch/uris/host_wang_legion_y9000p_irx8__40781
/rosversion
/run_id
/turtlesim/background_b
/turtlesim/background_g
/turtlesim/background_r
*/
#include "ros/ros.h"
int main(int argc,char *argv[]){
    ros::init(argc,argv,"change_bk");
    ros::NodeHandle nh;
    nh.setParam("background_r",0);
    nh.setParam("background_g",0);
    nh.setParam("background_b",0);

    return 0;
}