ROS2 humble tf2 examples

Installation:

  $ git clone https://github.com/UniversalRobots/Universal_Robots_ROS2_Driver
  
  $ cd Universal_Robots_ROS2_Driver

  $ git checkout humble

Run UR5 simulation:

  $ ros2 run ur_robot_driver start_ursim.sh -m ur5

  $ ros2 launch ur_robot_driver ur_control.launch.py ur_type:=ur5e robot_ip:=192.168.56.101 launch_rviz:=true

Publish static transform:

  $ ros2 run tf2_ros static_transform_publisher 0 0 0.1 0.0 0.0 0.0 tool0 gripper

Check transformations:

  $ ros2 run tf2_ros tf2_echo tool0 gripper

  $ ros2 run tf2_tools view_frames

Build package:

  $ colcon build
  
Example use:

  $ ros2 run tf_tutorial py_tf_listener
