/*
    需求: 实现基本的话题通信，一方发布数据，一方接收数据，
         实现的关键点:
         1.发送方
         2.接收方
         3.数据(此处为普通文本)

         PS: 二者需要设置相同的话题


    消息发布方:
        循环发布信息:HelloWorld 后缀数字编号

    实现流程:
        1.包含头文件 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 发布者 对象
        5.组织被发布的数据，并编写逻辑发布数据

*/

#include "std_msgs/String.h"
#include <sstream>
#include "ros/ros.h"

int main(int argc, char *argv[])
{   
    //设置编码
    setlocale(LC_ALL,"");
    //2.初始化 ROS 节点:命名(唯一)
    // 参数1和参数2 后期为节点传值会使用
    // 参数3 是节点名称，是一个标识符，需要保证运行后，在 ROS 网络拓扑中唯一
    ros::init(argc, argv, "talk");
    //实例化ros句柄
    ros::NodeHandle nh;
    //4.实例化 发布者 对象
    //泛型: 发布的消息类型
    //参数1: 要发布到的话题
    //参数2: 队列中最大保存的消息数，超出此阀值时，先进的先销毁(时间早的先销毁)
    ros::Publisher pub= nh.advertise<std_msgs::String>("chatter",10);

    //5.组织被发布的数据，并编写逻辑发布数据
    //数据(动态组织)
    std_msgs::String msg;
    std::string msg_front = "你好！";//消息前缀
    int count=0;
    //1秒10次
    ros::Rate r(1);

    while (ros::ok())
    {
        //使用stringstream拼接字符串与编号

        std::stringstream ss;
        ss << msg_front << count;
        msg.data = ss.str();
        //发布消息
        pub.publish(msg);
        //调试
        ROS_INFO("发送的消息：%s",msg.data.c_str());

        r.sleep();
        count++;
        ros::spinOnce();
    };
    

    return 0;

}
