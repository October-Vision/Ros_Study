//1.包含头文件
#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h" //注意: 调用 transform 必须包含该头文件

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");
    //2.初始化 ROS 节点
    ros::init(argc,argv,"dynamic_tf_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);

    ros::Rate r(1);

    while (ros::ok())
    {
        // 4.生成一个坐标点(相对于子级坐标系)
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id="turtle1"; // 子级坐标系
        point_laser.header.stamp = ros::Time::now();
        point_laser.point.x = 1.0;
        point_laser.point.y = 1.0;
        point_laser.point.z = 0.0;

        //转换坐标点（相对于父级坐标）
        try{
            geometry_msgs::PointStamped point_base;
            point_base=buffer.transform(point_laser,"world");
            ROS_INFO("转换后的数据:(%.2f,%.2f,%.2f),参考的坐标系是:%s",
                point_base.point.x,
                point_base.point.y,
                point_base.point.z,
                point_base.header.frame_id.c_str());
        }
        catch(const std::exception& e){
            ROS_ERROR("坐标转换失败: %s", e.what());
        }
        r.sleep();
        ros::spinOnce();
    }
    return 0;
}