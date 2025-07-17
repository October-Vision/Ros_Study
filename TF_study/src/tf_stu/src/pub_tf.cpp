/* 
    静态坐标变换发布方:
        发布关于 laser 坐标系的位置信息 

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建静态坐标转换广播器
        4.创建坐标系信息
        5.广播器发布坐标系信息
        6.spin()
*/
#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"tf_pub");
    //2.创建静态坐标转换广播器
    tf2_ros::StaticTransformBroadcaster broadcaster;
    //4.创建坐标系信息
    geometry_msgs::TransformStamped ts;
    //5.设置头信息
    ts.header.seq=100;
    ts.header.stamp=ros::Time::now();
    ts.header.frame_id="base_link";//基本坐标系（父坐标）

    ts.child_frame_id="laser";//子坐标系（子坐标）
    //6.设置偏移量offset

    ts.transform.translation.x=0.2;
    ts.transform.translation.y=0.0;
    ts.transform.translation.z=0.5;

    //设置四元数：将欧拉角转换为四元数

    tf2::Quaternion qtn;
    qtn.setRPY(0,0,0);//roll pitch yaw
    ts.transform.rotation.x=qtn.getX();
    ts.transform.rotation.y=qtn.getY();
    ts.transform.rotation.z=qtn.getZ();
    ts.transform.rotation.w=qtn.getW();

    //6.广播器发布坐标系信息
    broadcaster.sendTransform(ts);
    ros::spin();
    return 0;
}