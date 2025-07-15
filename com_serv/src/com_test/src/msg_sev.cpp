#include "ros/ros.h"
#include "com_test/Person.h"

void Doperson(const com_test::Person::ConstPtr& person_p){
    ROS_INFO("订阅的信息:%s,%d,%.2f",person_p->name.c_str(),person_p->age,person_p->height);
}

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"listen_person");
    ros::NodeHandle nh;
    ros::Subscriber sub= nh.subscribe<com_test::Person>("PersonMsg",10,Doperson);
    ros::spin();
    return 0;

}