
# 此份文件记录了ros学习过程

## 第一章 ros基础架构

### 1.1rosdep初始化失败

	对于rosdep初始化失败问题大多由于国外网站禁用问题，解决方法，查看https://gitee.com/zhao-xuzuo/rosdistro中的rosdistro/rosdep/sources.list.d/20-default.list部分，重点是查看URL调用的地方gitee.com/zhao-xuzuo/rosdistro/raw/master记住这个地址，很关键。
	随后进入/usr/lib/pyton3/dis-packages/文件夹中查找URL中有引用raw.githubusercontent.com的部分，可以使用如下命令find . -type f | xargs grep "raw.githubusercontent"
	可以查出主要有：./rosdistro/__init__.py、./rosdep2/gbpdistro_support.py、./rosdep2/sources_list.py 、./rosdep2/rep3.py。可以使用sudo gedit +文件名的方式修改,将里面涉及到的WRL引用部分的raw.githubusercontent.com/ros/rosdistro/master都替换为gitee.com/zhao-xuzuo/rosdistro/raw/master修改完成即可。
	重新运行sudo rosdep init(初始化，运行一次即可)
		rosdep update
	rosdep作用主要用于直接一键安装功能包里面提到的所需依赖文件缺失的依赖。
	
### 1.2创建ros工作空间及功能包

	实现流程：
	1.先创建一个工作空间；
	2.再创建一个功能包；
	3.编辑源文件；
	4.编辑配置文件；
	5.编译并执行。
	mkdir -p 空间名/src && cd 空间名 && catkiin_make
	cd src && catkin_create_pkg 包名 roscpp rospy std_msgs
	以上命令会在工作空间下生成一个功能包，该功能包依赖于 roscpp、rospy 与 std_msgs，其中roscpp是使用C++实现的库，而rospy则是使用python实现的库，std_msgs是标准消息库，创建ROS功能包时，一般都会依赖这三个库实现。
在ROS中，虽然实现同一功能时，C++和Python可以互换，但是具体选择哪种语言，需要视需求而定，因为两种语言相较而言:C++运行效率高但是编码效率低，而Python则反之，基于二者互补的特点，ROS设计者分别设计了roscpp与rospy库，前者旨在成为ROS的高性能库，而后者则一般用于对性能无要求的场景，旨在提高开发效率。

### 1.3简单代码实现
	源码需求主要分为3个部分
	1.初始化节点，包含节点名称(这里的实际节点名称要与cmakelist文件中生成的可执行文件名一样)
	2.算法行为（包含你写这段代码需要它做什么）（包含订阅与发布等行为）
	3.关闭节点
	CmakeList文件编写要点：
	add_executable(源文件名A src/节点所在文件名.cpp)
	target_link_libraries(源文件名B ${catkin_LIBRARIES})这里提到的源文件名A和B就是上面说到的节点名字，要保持一致。

### 1.4launch文件

	launch文件应该放在功能包里面，举例：文件结构.
		└── src
		    ├── CMakeLists.txt -> /opt/ros/noetic/share/catkin/cmake/toplevel.cmake
		    └── com_test
			├── CMakeLists.txt
			├── include
			│   └── com_test
			├── package.xml
			└── src
		这里的com_test是实际功能包，launch文件夹以及.launch文件都应放在com_test里面.
	.launch文件内容：

```xml
	<launch>
			<node pkg="helloworld" type="demo_hello" name="hello" output="screen" />
	</launch>
```
	这里
	node ---> 包含的某个节点
	pkg -----> 功能包也就是上面提到的com_test这个功能包的名字
	type ----> 被运行的节点文件(也就是节点名称，上诉提到的源文件名A和B和定义的节点名称)
	name --> 为节点命名（这个命名不会报错，重点看rqt中各节点关系）
	output-> 设置日志的输出目标
## 第二章 通讯
### 2.1话题通讯

	总的来说，话题通讯也就是在前面创建ros的工作空间下增加了一个发送和接受的过程，也可以叫做发布与接收。
	发布方总体流程可以大概分为5步：1.设置编码格式，2.初始化（包含节点名称等）这里纠正上面第一章说的这里的初始化节点名称要与源文件名A和B相等这个说法，可以不用一样也不会报错，不过出于方便管理还是建议使用一样的命名方式。3.实例化ros句柄 4.实例化发布者对象 5.组织被发布的数据并编写逻辑发送数据
	订阅方大致可以分为5个流程：1.初始化ROS节点 2.实例化ROS句柄 3.实例化订阅者对象 4.处理订阅的消息(回调函数) 6.设置循环调用回调函数

	问题探究：在这里我遇见能找到功能包但是找不到节点的问题，问题分析：ros通过rosrun运行节点时需要在devel/lib/包名/中寻找编译好的可执行文件(如cmakelist里面add_executable(pub_test src/test_pub.cpp)写到的pub_test)当时由于cmakelsit里面catkin_make()位置写在了include_distrectories()和add_executable()后面，发现了链接异常。这里正确的写法应该是catkin_make()需要放在include_directories()的后面和add_executable()的前面，也就是
	

	# 先包含头文件目录
	include_directories(
	${catkin_INCLUDE_DIRS}
	)

	# 再声明catkin_package（必须在add_executable之前）
	catkin_package(
	# INCLUDE_DIRS include
	# LIBRARIES com_test
	# CATKIN_DEPENDS roscpp rospy std_msgs
	# DEPENDS system_lib
	)

	# 编译可执行文件
	add_executable(pub_test src/test_pub.cpp)  # 确保源文件路径正确
	add_executable(sev_test src/test_sev.cpp)  

	# 链接库
	target_link_libraries(pub_test
	${catkin_LIBRARIES}
	)

### 2.2launch文件的多终端打开
	使用launch-prefix="gnome-terminal -- bash -c 'rosrun com_test pub_test; exec bash'"这一行命令可以实现每个节点新开终端，具体使用方法(这是一个简单的话题通讯节点)如下：
```xml	
	<launch>
		<node 
			pkg="com_test" 
			type="pub_test" 
			name="pub" 
			output="screen"
			launch-prefix="gnome-terminal -- bash -c 'rosrun com_test pub_test; exec bash'"
		/>
		<node 
			pkg="com_test" 
			type="sev_test" 
			name="sev" 
			output="screen"
			launch-prefix="gnome-terminal -- bash -c 'rosrun com_test sev_test; exec bash'"
		/>  
	</launch>
```
### 2.3原理分析
	ros的通讯机制是基于话题（topic）的异步通讯:所有向同一话题发布消息的节点（发布者），其消息会被所有订阅该话题的节点(订阅者),如果想实现分别订阅可以更换话题名称，比如c++用chatter_cpp话题，python用chatter_py由于ros的话题是可以自由定义的，因此按需选择将好。
	并且一个发布者可以同时向多个话题中发布消息，只需pub=rospy.Publisher("话题名称"，String,que_size=10) 这里String是代表消息的数据类型这里的String表示消息中只有一个字符串数据，其他消息类型还有std_msgs/INT32:整数，std_msgs/Float64浮点数,geometry_msgs/Pose位置和姿态，sensor_msgs_Image图像数据，自定义消息类型(需要自己创建.msg文件并编译)。queue_size指定发布者内部队列的最大容量(即最多缓存多少条消息)。如果队列满了，新的消息会挤掉最早的消息(既先进先出原则，FIFO)。
