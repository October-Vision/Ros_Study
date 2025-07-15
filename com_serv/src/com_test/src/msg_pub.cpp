#include "ros/ros.h"
#include "com_test/Person.h"

int main(int argc,char *argv[]){

    setlocale(LC_ALL,"");

    ros::init(argc,argv,"talker_msg");

    ros::NodeHandle nh;

    ros::Publisher pub =nh.advertise<com_test::Person>("PersonMsg",1000);

    com_test::Person p;

    p.name="wang";

    p.age=2000;

    p.height=165.2;

    ros::Rate r(1);
    while (ros::ok())
    {
        pub.publish(p);
        p.age +=1;
        ROS_INFO("发布的名字：%s,年龄:%d,高度：%.2f",p.name.c_str(),p.age,p.height);
        r.sleep();
        ros::spinOnce();
    }
    return 0;
}