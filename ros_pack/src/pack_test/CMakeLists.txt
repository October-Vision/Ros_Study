cmake_minimum_required(VERSION 3.0.2)
project(pack_test)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package()  # 普通包用 catkin_package()，而非 catkin_metapackage()

# 安装 launch 目录（关键：让 ROS 识别 launch 文件）
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  FILES_MATCHING PATTERN "*.launch"  # 只安装 .launch 文件
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)