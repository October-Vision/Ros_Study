/*  
    动态的坐标系相对姿态发布(一个坐标系相对于另一个坐标系的相对姿态是不断变动的)

    需求: 启动 turtlesim_node,该节点中窗体有一个世界坐标系(左下角为坐标系原点)，乌龟是另一个坐标系，键盘
    控制乌龟运动，将两个坐标系的相对位置动态发布

    实现分析:
        1.乌龟本身不但可以看作坐标系，也是世界坐标系中的一个坐标点
        2.订阅 turtle1/pose,可以获取乌龟在世界坐标系的 x坐标、y坐标、偏移量以及线速度和角速度
        3.将 pose 信息转换成 坐标系相对信息并发布

    实现流程:
        1.包含头文件
        2.初始化 ROS 节点
        3.创建 ROS 句柄
        4.创建订阅对象
        5.回调函数处理订阅到的数据(实现TF广播)
            5-1.创建 TF 广播器
            5-2.创建 广播的数据(通过 pose 设置)
            5-3.广播器发布数据
        6.spin
*/

#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

void domsg(const turtlesim::Pose::ConstPtr& pose){
    static tf2_ros::TransformBroadcaster broadcaster;
    geometry_msgs::TransformStamped tfs;

    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "world"; // 父级坐标系

    tfs.child_frame_id = "turtle1"; // 子级坐标系
    tfs.transform.translation.x = pose->x; // 子级坐标系在父级坐标系中的位置
    tfs.transform.translation.y = pose->y;
    tfs.transform.translation.z = 0.0; // z轴坐标为0

    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();

    broadcaster.sendTransform(tfs);
    ROS_INFO("发布坐标系: %s, 位置:(%.2f, %.2f, %.2f), 角度: %.2f",
        tfs.child_frame_id.c_str(),
        tfs.transform.translation.x,
        tfs.transform.translation.y,
        tfs.transform.translation.z,
        pose->theta);
    // 注意: 发布的坐标系是动态的，随着乌龟的运动
}

int main(int argc , char *agrv[]){
    setlocale(LC_ALL,"");
    ros::init(argc, agrv ,"tf_dynamic_pub");

    ros::NodeHandle nh;

    ros::Subscriber sub=nh.subscribe<turtlesim::Pose>("turtle1/pose",10,domsg);
    ros::spin();
    return 0;

}