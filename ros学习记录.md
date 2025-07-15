
# 此份文件记录了ros学习过程
这里感谢赵虚左的开源文档，本次学习基于http://www.autolabor.com.cn/book/ROSTutorials/
本篇文档只纪录我认为关键的某些地方以及遇见的问题和解决方案，对于相关概念请查看网站文档。
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
	话题通信是ROS中使用频率最高的一种通信模式，话题通信是基于发布订阅模式的，也即:一个节点发布消息，另一个节点订阅该消息。话题通信的应用场景也极其广泛

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

### 2.4自定义msg消息通讯
	在ros通讯协议中，数据载体是一个较为重要的组成部分，ROS中通过std_msgs封装了一些原生数据类型比如:String、Int32、Int64、Char、Bool、Empty.... 但是，这些数据一般只包含一个 data 字段，结构的单一意味着功能上的局限性，当传输一些复杂的数据，比如: 激光雷达的信息... std_msgs 由于描述性较差而显得力不从心，这种场景下可以使用自定义的消息类型
	msgs只是简单的文本文件，每行具有字段类型和字段名称，可以使用的字段类型有：
	int8,int16,int32,(或者无符号类型uint*)
	float32，float64
	string
	time,duration
	variable-length array[] and fixed-length array[C]
	ROS中还有一种特殊类型：Header，标头包含时间戳和ROS中常用的坐标帧信息。会经常看到msg文件的第一行具有Header标头。
	在这里定也一个msg消息通讯流程可分为以下几步：
	1.在功能包下新建目录，添加文件Person.msg包含所需要的消息类型
	目录信息参考：
	src
    ├── CMakeLists.txt -> /opt/ros/noetic/share/catkin/cmake/toplevel.cmake
    └── com_test
        ├── CMakeLists.txt
        ├── include
        │   └── com_test
        ├── launch
        │   └── comcation.launch
        ├── msg
        │   └── Person.msg
        ├── package.xml
        └── src
            ├── msg_pub.cpp
            ├── msg_sev.cpp
	Person.msg文件内容(这里简单演示)：
```bash
	string name
	uint16 age
	float64 height
```	
	2.编辑配置文件
	package.xml
		在添加完自定义消息后，需要在package.xml中添加编译依赖和执行依赖
```xml
	<build_depend>message_generation</build_depend>
	<exec_depend>message_runtime</exec_depend>
```
	cmakelist.txt
		在cmakelist中编辑msg相关配置
```bash
	find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	std_msgs
	message_generation
	)
	# 需要加入 message_generation,必须有 std_msgs
	## 配置 msg 源文件
	add_message_files(
	FILES
	Person.msg
	)
	# 生成消息时依赖于 std_msgs
	generate_messages(
	DEPENDENCIES
	std_msgs
	)
	#执行时依赖
	catkin_package(
	#  INCLUDE_DIRS include
	#  LIBRARIES demo02_talker_listener
	CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
	#  DEPENDS system_lib
	)
```
	3.编译生成头文件
		这里配置完成之后直接编译可以看到在/devel/include/目录下出现了相关.h文件(我这里是Person.h)就表示成功。
		注：c++的目录在/devel/include/功能包名/消息名.h
			python的目录在/devel/lib/python3/dist-packages/包名/msg
	4.调用自定义的msg消息
		流程：
		1.编写发布方实现
		2.编写订阅方实现
		3.编辑配置文件
		4.编译并执行
	发布方代码详见com_serv/src/com_test/src/msg_pub.cpp(c++版本)
	订阅方详见com_serv/src/com_test/src/msg_sev.cpp(c++版本)
	这里只写遇见的某些问题
		头文件相关：
			其中最开始出现#inlcude "com_serv/Person.h"找不到头文件的问题
			这里是因为自定义消息是放在功能包/msg/Person.msg里面的，所以正确的写法应该是
```bash
			#include "com_test/Person.h"
```
			也就是说应该包含的是当前功能包的名称下的Person.h
		
		CmakeList相关：
			当然修改完代码CmakeList.txt文件里也得注意，在这里面需要多添加
			add_dependencies(节点名称 ${PROJIECT_NAME}_generae_messages_cpp)
			当然也得注意位置关系，示例：
```bash
add_executable(msg_pub_test src/msg_pub.cpp)
add_executable(msg_sev_test src/msg_sev.cpp)

add_dependencies(msg_pub_test ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(msg_sev_test ${PROJECT_NAME}_generate_messages_cpp)

target_link_libraries(msg_pub_test ${catkin_LIBRARIES})
target_link_libraries(msg_sev_test ${catkin_LIBRARIES})
```

### 2.5服务通讯
	服务通信也是ROS中一种极其常用的通信模式，服务通信是基于请求响应模式的，是一种应答机制。也即: 一个节点A向另一个节点B发送请求，B接收处理请求并产生响应结果返回给A。
	概念：以请求响应的方式实现不同节点之间数据交互的通信模式。
	作用：用于偶然的、对时时性有要求、有一定逻辑处理需求的数据传输场景。
	服务通讯主要可以理解为下面几个步骤：
	0.Server注册，也叫做服务端注册，Server 启动后，会通过RPC在 ROS Master 中注册自身信息，其中包含提供的服务的名称。ROS Master 会将节点的注册信息加入到注册表中。
	1.Client注册，也叫客户端注册：Client 启动后，也会通过RPC在 ROS Master 中注册自身信息，包含需要请求的服务的名称。ROS Master 会将节点的注册信息加入到注册表中。
	2.ROS Master实现信息匹配：也就是根据注册表的信息匹配server和client，并通过RPC向Client发送Server的TCP地址信息
	3.Client发送请求：Client根据步骤2响应的信息利用TCP与Server建立网络连接，并发送请求数据
	4.Server发送响应：Server接收、解析请求的数据后，把结果返回给Client。
	注：客户端请求被处理时需要保证服务器已经启动，代码里写的堵塞也是为了保证服务器正常启动后才进行处理 并且服务端和客户端可以存在多个。
### 2.6自定义srv
	srv 文件内的可用数据类型与 msg 文件一致，且定义 srv 实现流程与自定义 msg 实现流程类似:
	按照固定格式创建srv文件
	编辑配置文件
	编译生成中间文件
	流程步骤与上面创建自定义msg类型差不多，这里主要只写相对差别：
	文件和msg文件放在同级目录下命名为srv，文件以srv结尾，内容方面客户端请求数据与服务器端响应数据用---分割开
	示例：
```bash
	int32 num1
	int32 num2
	#上面为客户端数据
	---
	#下面为服务端数据
	int32 sum3
```
	配置文件方面，package.xml文件与上面msg消息类型一致，cmakelist也和上面msg差不多，唯一差别在需要单独加一条
```bash
		add_service_files(
			FILES
			文件名.srv
		)
```
	编译后的生成位置是差不多的。
### srv的调用
	流程如下：
		编写服务端实现；
		编写客户端实现；
		编辑配置文件；
		编译并执行
	这里的详细代码请查阅/com_test/src/srv_msg_client.cpp和srv_msg_service.cpp这里就不过多赘述这里简单讲讲遇见的问题，讲义上的内容都没太多需要讲述的地方，这里主要讲讲优化部分。
	通过launch文件管理节点，这里的launch文件详见com_test/launch/server.launch这里使用到了私有命名空间，也就是ros::NodeHandle nh('~')这个是ROS C++API中用于获取节点私有命名空间的写法，用于隔离节点的参数和话题，可以避免命名冲突，举一个简单的例子，当我在ADDsum这个服务中定义了一个参数名为num1，在另一个节点服务SUMABC中定义了一个参数名也为num1由于ROS中参数和话题都是全局的，多个节点之间相同参数命名会出现冲突，因此这个私有空间就可以将参数私有化，在调用时就指定了是ADDsum中的num1参数。
	具体含义:ros::NodeHandle：ROS 节点的句柄，用于创建话题、服务、参数等。"~"：表示节点的私有命名空间（相对路径），与节点名称绑定。例如，若节点名为 sum_client，则私有命名空间为 sum_client/。
	这里私有命名空间的参数：/节点名/参数名(例：/ADDsum/num1)
	全局命名参数：/参数名(例：/num1很有可能被其他节点覆盖)
	使用场景：当使用nh('~')来创建句柄时，调用nh.Param(...)来优先读取节点私有参数(通常从launch文件中传递)：
```bash
	ros::NodeHandle nh("~");  // 私有命名空间句柄
	int num1;
	// 从私有命名空间读取参数 num1，默认值为 0
	nh.param("num1", num1, 0);  
```
```xml
	<node name="sum_client" pkg="com_test" type="srv_client" output="screen">
	<!-- 传递私有参数：会被节点的 nh("~") 读取 -->
	<param name="num1" value="15" />  
	<param name="num2" value="30" />
	</node>
```
注意，由于使用了私有节点参数，服务端服务名称前得加上/.例如:
ros::ServiceClient client =nh.serviceClient<com_test::ADDsum>("/ADDsum");

对比: 
ros::NodeHandle nh  全局命名空间  /num1（可能冲突）
ros::NodeHandle nh("~") 私有命名空间  /sum_client/num1（隔离，安全）
ros::NodeHandle nh("ns") 自定义命名空间  /ns/num1（手动指定命名空间）

	使用launch文件中的if="$(arg run_client)"参数
	这是 ROS launch 文件中的语法，用于根据参数值决定是否启动某个节点，实现节点的条件化启动。
	$(arg run_client)：获取 launch 文件中定义的参数 run_client 的值（通常是 true 或 false）。
	if="..."当引号内的值为true时才会启动当前的节点，为false时就不启动，跳过该节点。

	使用场景，例：
```xml
<launch>
	<!-- 定义一个参数 run_client，默认值为 true -->
	<arg name="run_client" default="true" />

	<!-- 服务端节点：总是启动 -->
	<node name="sum_server" pkg="com_test" type="srv_server" output="screen" />

	<!-- 客户端节点：仅当 run_client 为 true 时启动 -->
	<node 
		name="sum_client" 
		pkg="com_test" 
		type="srv_client" 
		output="screen" 
		if="$(arg run_client)"  
	/>
</launch>
```
```bash
	# 启动服务端 + 客户端（默认，因为 run_client 默认 true）
	roslaunch com_test sum_service.launch

	# 只启动服务端，不启动客户端（手动指定 run_client 为 false）
	roslaunch com_test sum_service.launch run_client:=false
```
	总结，可以更好的控制节点启动。

### 参数服务器
	参数服务器设计三个角色：ROS Master Talker Listener
	ROS Master 作为一个公共容器保存参数，Talker 可以向容器中设置参数，Listener 可以获取参数。
	流程：
	1.Talker设置参数：Talker 通过 RPC 向参数服务器发送参数(包括参数名与参数值)，ROS Master 将参数保存到参数列表中。
	2.Listener 获取参数：Listener 通过 RPC 向参数服务器发送参数查找请求，请求中包含要查找的参数名。
	3.ROS Master 向 Listener 发送参数值：ROS Master 根据步骤2请求提供的参数名查找参数值，并将查询结果通过 RPC 发送给 Listener
	
	数据类型：
	32-bit integers
	booleans
	strings
	doubles
	iso8601 dates
	lists
	base64-encoded binary data
	字典
	注：参数服务器不是为高性能设计，最好用于存储非二进制的简单数据
