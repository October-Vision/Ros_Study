/*  
    订阅 turtle1 和 turtle2 的 TF 广播信息，查找并转换时间最近的 TF 信息
    将 turtle1 转换成相对 turtle2 的坐标，在计算线速度和角速度并发布

    实现流程:
        1.包含头文件
        2.初始化 ros 节点
        3.创建 ros 句柄
        4.创建 TF 订阅对象
        5.处理订阅到的 TF
        6.spin

*/

#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"two_turtle_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener Listener(buffer);

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 1000);

    ros::Rate r(10);
    while (ros::ok())
    {
        try{
            geometry_msgs::TransformStamped tfs =buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
           
           geometry_msgs::Twist twist;
            twist.linear.x=0.5*sqrt(pow(tfs.transform.translation.x,2)+pow(tfs.transform.translation.y,2));
            twist.angular.z=4 * atan2(tfs.transform.translation.y,tfs.transform.translation.x);
            pub.publish(twist);

        }
        catch(const std::exception& e){
            ROS_ERROR("坐标转换失败: %s", e.what());
        }
        r.sleep();
        ros::spinOnce();
    }
    return 0;
    
}