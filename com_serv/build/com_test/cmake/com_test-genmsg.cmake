# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "com_test: 1 messages, 1 services")

set(MSG_I_FLAGS "-Icom_test:/home/wang/ros_study/com_serv/src/com_test/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(com_test_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg" NAME_WE)
add_custom_target(_com_test_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "com_test" "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg" ""
)

get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv" NAME_WE)
add_custom_target(_com_test_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "com_test" "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(com_test
  "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/com_test
)

### Generating Services
_generate_srv_cpp(com_test
  "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/com_test
)

### Generating Module File
_generate_module_cpp(com_test
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/com_test
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(com_test_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(com_test_generate_messages com_test_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg" NAME_WE)
add_dependencies(com_test_generate_messages_cpp _com_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv" NAME_WE)
add_dependencies(com_test_generate_messages_cpp _com_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(com_test_gencpp)
add_dependencies(com_test_gencpp com_test_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS com_test_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(com_test
  "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/com_test
)

### Generating Services
_generate_srv_eus(com_test
  "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/com_test
)

### Generating Module File
_generate_module_eus(com_test
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/com_test
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(com_test_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(com_test_generate_messages com_test_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg" NAME_WE)
add_dependencies(com_test_generate_messages_eus _com_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv" NAME_WE)
add_dependencies(com_test_generate_messages_eus _com_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(com_test_geneus)
add_dependencies(com_test_geneus com_test_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS com_test_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(com_test
  "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/com_test
)

### Generating Services
_generate_srv_lisp(com_test
  "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/com_test
)

### Generating Module File
_generate_module_lisp(com_test
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/com_test
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(com_test_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(com_test_generate_messages com_test_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg" NAME_WE)
add_dependencies(com_test_generate_messages_lisp _com_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv" NAME_WE)
add_dependencies(com_test_generate_messages_lisp _com_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(com_test_genlisp)
add_dependencies(com_test_genlisp com_test_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS com_test_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(com_test
  "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/com_test
)

### Generating Services
_generate_srv_nodejs(com_test
  "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/com_test
)

### Generating Module File
_generate_module_nodejs(com_test
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/com_test
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(com_test_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(com_test_generate_messages com_test_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg" NAME_WE)
add_dependencies(com_test_generate_messages_nodejs _com_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv" NAME_WE)
add_dependencies(com_test_generate_messages_nodejs _com_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(com_test_gennodejs)
add_dependencies(com_test_gennodejs com_test_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS com_test_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(com_test
  "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/com_test
)

### Generating Services
_generate_srv_py(com_test
  "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/com_test
)

### Generating Module File
_generate_module_py(com_test
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/com_test
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(com_test_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(com_test_generate_messages com_test_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/msg/Person.msg" NAME_WE)
add_dependencies(com_test_generate_messages_py _com_test_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/wang/ros_study/com_serv/src/com_test/srv/ADDsum.srv" NAME_WE)
add_dependencies(com_test_generate_messages_py _com_test_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(com_test_genpy)
add_dependencies(com_test_genpy com_test_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS com_test_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/com_test)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/com_test
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(com_test_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/com_test)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/com_test
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(com_test_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/com_test)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/com_test
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(com_test_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/com_test)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/com_test
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(com_test_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/com_test)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/com_test\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/com_test
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(com_test_generate_messages_py std_msgs_generate_messages_py)
endif()
