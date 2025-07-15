cmake_minimum_required(VERSION 3.0.2)
project(com_test)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
#  INCLUDE_DIRS include
)
catkin_install_python(PROGRAMS
  script/pub_py.py
  script/sev_py.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

#添加链接库
add_executable(pub_test src/test_pub.cpp)
add_executable(sev_test src/test_sev.cpp)

target_link_libraries(pub_test  ${catkin_LIBRARIES})
target_link_libraries(sev_test ${catkin_LIBRARIES})


