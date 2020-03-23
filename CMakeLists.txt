################################################################################
# Set minimum required version of cmake, project name and compile options
################################################################################
cmake_minimum_required(VERSION 2.8.3)
project(tf_tutorial)

################################################################################
# Find catkin packages and libraries for catkin and system dependencies
################################################################################
find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
  sensor_msgs
)

################################################################################
# Declare catkin specific configuration to be passed to dependent projects
################################################################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES opencv_example2
   CATKIN_DEPENDS roscpp std_msgs message_runtime sensor_msgs
#  DEPENDS system_lib
)

################################################################################
# Build
################################################################################
include_directories(include ${catkin_INCLUDE_DIRS}) 

add_executable(move_up_node src/move_up.cpp)

target_link_libraries(move_up_node ${catkin_LIBRARIES})
add_dependencies(move_up_node ${PROJECT_NAME}_generate_messages_cpp)

################################################################################
# Install
################################################################################
install(DIRECTORY launch tf_tutorial param rviz 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

################################################################################
# Test
################################################################################
