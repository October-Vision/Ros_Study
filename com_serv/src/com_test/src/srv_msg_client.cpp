//客户端
#include "ros/ros.h"
#include "com_test/ADDsum.h"
// //方案1使用终端传递参数，启动时在终端输入rosrun 功能包名 节点名字 参数1 参数2
// int main(int argc, char* argv[]){
//     setlocale(LC_ALL,"");
//     //调用时动态传值，如果通过launch的args传参数，需要传递的参数个数+3
//     // if (argc != 5)//launch 传参(0-文件路径 1传入的参数 2传入的参数 3节点名称 4日志路径)
//     if(argc !=3){
//         ROS_ERROR("参数过少");
//         return 1;
//     }
//     ros::init(argc,argv,"sum_client");
//     ros::NodeHandle nh;
//     //创建客户端对象
//     ros::ServiceClient client = nh.serviceClient<com_test::ADDsum>("ADDsum");


//     //优化1：阻塞等待服务可用，超市时间设置为5s这里和下面方法1和2是一样的不同在与方法1和2会一直等待。
//     if(!client.waitForExistence(ros::Duration(5.0))){
//         ROS_ERROR("等待服务超时，服务未启动");
//         return 1;
//     }
//     //方法1：
//     //ros::service::waitForService("ADDsum"，ros::Duration(5.0));ros::duration主要用于限定等待时间。
//     //方法2：
//     //client.waitForExistence();
//     //组织请求数据

//     com_test::ADDsum ai;
//     ai.request.num1=atoi(argv[1]);
//     ai.request.num2=atoi(argv[2]);
//     //发送请求，返回bool值,标记是否成功
//     bool flag=client.call(ai);

//     //处理响应
//     if(flag){
//         ROS_INFO("请求正常处理，结果:%d",ai.response.sum);
//     }else{
//         ROS_ERROR("处理失败");
//         return 1;
//     }
//     return 0;
// }
//方案2通过launch启动
int main(int argc,char *argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"sum_client");
    ros::NodeHandle nh("~");
    int num1=0,num2=0;
    nh.param("num1",num1,0);
    nh.param("num2",num2,0);

    // 如果参数未通过launch传递，则检查命令行参数
    if(argc > 1){
        num1 = atoi(argv[1]);
    }
    if(argc > 2){
        num2 = atoi(argv[2]);
    }
    
    // 验证参数有效性
    if(num1 == 0 && num2 == 0){
        ROS_ERROR("未提供有效参数");
        return 1;
    }

    ros::ServiceClient client =nh.serviceClient<com_test::ADDsum>("/ADDsum");
    if(!client.waitForExistence(ros::Duration(5.0))){
        ROS_ERROR("client start error");
        return 1;
    }

    com_test::ADDsum ai;
    ai.request.num1=num1;
    ai.request.num2=num2;
    bool flag=client.call(ai);

    // 处理响应
    if(flag){
        ROS_INFO("请求正常处理，结果:%d",ai.response.sum);
    }else{
        ROS_ERROR("处理失败");
        return 1;
    }
}