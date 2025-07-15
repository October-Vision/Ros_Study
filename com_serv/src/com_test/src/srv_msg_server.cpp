#include "ros/ros.h"
#include "com_test/ADDsum.h"

bool doReq(com_test::ADDsum::Request& req,com_test::ADDsum::Response& resp){
    int num1=req.num1;
    int num2=req.num2;
    ROS_INFO("服务器收到的请求数据为:num1=%d,num2=%d",num1,num2);
    if(num1<0||num2<0){
        ROS_ERROR("提交数据异常，负数");
        return false;
    }
    resp.sum=num1+num2;
    return true;
}

int main(int argc,char* argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sum_server");

    ros::NodeHandle nh;

    ros::ServiceServer server =nh.advertiseService("ADDsum",doReq);
    ROS_INFO("服务已启动");

    ros::spin();
    return 0;

}