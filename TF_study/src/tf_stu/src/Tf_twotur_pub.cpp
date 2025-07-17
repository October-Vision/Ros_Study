/*  
    该文件实现:需要订阅 turtle1 和 turtle2 的 pose，然后广播相对 world 的坐标系信息

    注意: 订阅的两只 turtle,除了命名空间(turtle1 和 turtle2)不同外,
          其他的话题名称和实现逻辑都是一样的，
          所以我们可以将所需的命名空间通过 args 动态传入

    实现流程:
        1.包含头文件
        2.初始化 ros 节点
        3.解析传入的命名空间
        4.创建 ros 句柄
        5.创建订阅对象
        6.回调函数处理订阅的 pose 信息
            6-1.创建 TF 广播器
            6-2.将 pose 信息转换成 TransFormStamped
            6-3.发布
        7.spin

*/

#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2/LinearMath/Quaternion.h"
#include "geometry_msgs/TransformStamped.h"

std::string turtle_name;


void dopose(const turtlesim::Pose::ConstPtr& pose){
    static tf2_ros::TransformBroadcaster broadcaster;

    geometry_msgs::TransformStamped tfs;

    tfs.header.frame_id = "world"; // 父级坐标系
    tfs.header.stamp=ros::Time::now();
    tfs.child_frame_id=turtle_name;
    tfs.transform.translation.x=pose->x; // 子级坐标系在父级坐标系中的位置
    tfs.transform.translation.y=pose->y;
    tfs.transform.translation.z=0.0; // z轴坐标为0

    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ(); 
    tfs.transform.rotation.w=  qtn.getW();

    broadcaster.sendTransform(tfs);
    ROS_INFO("发布坐标系: %s, 位置:(%.2f, %.2f, %.2f), 角度: %.2f",
        tfs.child_frame_id.c_str(),
        tfs.transform.translation.x,
        tfs.transform.translation.y,
        tfs.transform.translation.z,
        pose->theta);
}

int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"two_tur_pub");

    if(argc < 2){
        ROS_ERROR("请传入乌龟的命名空间");
        return -1;
    }else{
        turtle_name = argv[1]; // 解析传入的命名空间
    }
    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe<turtlesim::Pose>(turtle_name+"/pose",1000,dopose);

    ros::spin();
    return 0;

}