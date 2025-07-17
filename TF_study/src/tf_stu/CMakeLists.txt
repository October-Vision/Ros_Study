cmake_minimum_required(VERSION 3.0.2)
project(tf_stu)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  tf2
  tf2_geometry_msgs
  tf2_ros
)


catkin_package(
  CATKIN_DEPENDS 
    roscpp 
    rospy 
    std_msgs 
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS


  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

add_executable(tf_stu_node src/stu_tf.cpp)
add_executable(tf_pub_node src/pub_tf.cpp)
add_executable(dynamic_tf_pub src/tur_tf.cpp)
add_executable(dynamic_tf_sub src/tur_tf_sub.cpp)
add_executable(multipe_frame src/multipe_frame_sub.cpp)
add_executable(Tf_twotur_add src/Tf_twotur_add.cpp)
add_executable(Tf_twotur_pub src/Tf_twotur_pub.cpp)
add_executable(Tf_twotur_sub src/Tf_twotur_sub.cpp)

target_link_libraries(tf_stu_node
  ${catkin_LIBRARIES}
)
target_link_libraries(tf_pub_node
  ${catkin_LIBRARIES}
)
target_link_libraries(dynamic_tf_pub
  ${catkin_LIBRARIES}
)
target_link_libraries(dynamic_tf_sub
  ${catkin_LIBRARIES}
)
target_link_libraries(multipe_frame
  ${catkin_LIBRARIES}
)
target_link_libraries(Tf_twotur_add
  ${catkin_LIBRARIES}
)
target_link_libraries(Tf_twotur_pub
  ${catkin_LIBRARIES}
)
target_link_libraries(Tf_twotur_sub
  ${catkin_LIBRARIES}
)