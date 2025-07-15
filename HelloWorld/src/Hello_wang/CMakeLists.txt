cmake_minimum_required(VERSION 3.0.2)
project(hello_wang)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(

)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS scripts/py_hello_world.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

add_executable(hello_wps src/Hello.cpp)

target_link_libraries(hello_wps ${catkin_LIBRARIES})
