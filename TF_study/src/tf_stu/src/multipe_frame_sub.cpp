/*

需求:
    现有坐标系统，父级坐标系统 world,下有两子级系统 son1，son2，
    son1 相对于 world，以及 son2 相对于 world 的关系是已知的，
    求 son1 与 son2中的坐标关系，又已知在 son1中一点的坐标，要求求出该点在 son2 中的坐标
实现流程:
    1.包含头文件
    2.初始化 ros 节点
    3.创建 ros 句柄
    4.创建 TF 订阅对象
    5.解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
      解析 son1 中的点相对于 son2 的坐标
    6.spin

*/

#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/PointStamped.h"

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"sub_frame");
    ros::NodeHandle nh;
    // 3.创建 TF 订阅对象
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    //解析订阅信息中获取 son1 坐标系原点在 son2 中的坐标
    ros::Rate r(1);
    while (ros::ok()){
        try{
            geometry_msgs::TransformStamped tfs=buffer.lookupTransform("son2","son1",ros::Time(0));
            ROS_INFO("Son1 相对于 Son2 的坐标关系:父坐标系ID=%s",tfs.header.frame_id.c_str());
            ROS_INFO("Son1 相对于 Son2 的坐标关系:子坐标系ID=%s",tfs.child_frame_id.c_str());
            ROS_INFO("Son1 相对于 Son2 的坐标关系:位置(%.2f, %.2f, %.2f)",
                tfs.transform.translation.x,
                tfs.transform.translation.y,
                tfs.transform.translation.z
            );

            //坐标点解析

            geometry_msgs::PointStamped ps;

            ps.header.frame_id = "son1"; 
            ps.header.stamp =ros::Time::now();
            ps.point.x = 1.0; // son1 中的点
            ps.point.y = 2.0;
            ps.point.z = 3.0;

            geometry_msgs::PointStamped psAtson2;
            psAtson2 = buffer.transform(ps,"son2");
            ROS_INFO("Son1 中的点在 Son2 中的坐标:(%.2f, %.2f, %.2f),参考坐标系:%s",
                psAtson2.point.x,
                psAtson2.point.y,
                psAtson2.point.z,
                psAtson2.header.frame_id.c_str());
        }
        catch(const std::exception& e){
            ROS_ERROR("坐标转换失败: %s", e.what());
        }
        r.sleep();
        ros::spinOnce();
    }
}