cmake_minimum_required(VERSION 3.0.2)
project(com_test)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_message_files(
  FILES
  Person.msg
)

add_service_files(
  FILES
  ADDsum.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
#  INCLUDE_DIRS include
  CATKIN_DEPENDS 
  roscpp 
  rospy 
  std_msgs 
  message_runtime
)
catkin_install_python(PROGRAMS
  script/pub_py.py
  script/sev_py.py
  script/msg_py_pub.py
  script/msg_py_sev.py
  script/srv_client.py
  script/srv_server.py
  script/param_update.py
  script/param_search.py
  script/param_detele.py
  script/control_tur.py
  script/sub_pose.py
  script/srv_tur_ser.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

#添加链接库
add_executable(pub_test src/test_pub.cpp)
add_executable(sev_test src/test_sev.cpp)
add_executable(msg_pub_test src/msg_pub.cpp)
add_executable(msg_sev_test src/msg_sev.cpp)
add_executable(srv_server src/srv_msg_server.cpp)
add_executable(srv_client src/srv_msg_client.cpp)
add_executable(Param_update src/Param_update.cpp)
add_executable(Param_search src/Param_search.cpp)
add_executable(Param_delete src/param_delete.cpp)
add_executable(control_tur src/turtlesim_control.cpp)
add_executable(sub_pose src/control_show.cpp)
add_executable(srv_curtle src/srv_tur_ser.cpp)

add_dependencies(msg_pub_test ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(msg_sev_test ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(srv_server ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(srv_client ${PROJECT_NAME}_generate_messages_cpp)

target_link_libraries(pub_test  ${catkin_LIBRARIES})
target_link_libraries(sev_test ${catkin_LIBRARIES})
target_link_libraries(msg_pub_test ${catkin_LIBRARIES})
target_link_libraries(msg_sev_test ${catkin_LIBRARIES})
target_link_libraries(srv_server ${catkin_LIBRARIES})
target_link_libraries(srv_client ${catkin_LIBRARIES})
target_link_libraries(Param_update ${catkin_LIBRARIES})
target_link_libraries(Param_search ${catkin_LIBRARIES})
target_link_libraries(Param_delete ${catkin_LIBRARIES})
target_link_libraries(control_tur ${catkin_LIBRARIES})
target_link_libraries(sub_pose ${catkin_LIBRARIES})
target_link_libraries(srv_curtle ${catkin_LIBRARIES})