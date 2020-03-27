#include "ros/ros.h"
#include "ros/package.h"
#include "ros/this_node.h"
#include <iostream>

#include "control_msgs/JointTrajectoryControllerState.h" //read state of the arm
#include "control_msgs/FollowJointTrajectoryAction.h" //set goal positions
#include "sensor_msgs/JointState.h"
#include "std_msgs/String.h"
#include "moveit_msgs/GetPositionIK.h"
#include "moveit_msgs/GetPositionFK.h"
#include "moveit_msgs/DisplayRobotState.h"

#include <stdio.h>

using namespace std;

ros::Publisher ctrlPub;//control the robot

int main(int argc, char **argv) {
    //initialize node
    ros::init(argc, argv, "node_example");
    // node handler
    ros::NodeHandle n;

    ctrlPub = n.advertise<control_msgs::FollowJointTrajectoryActionGoal>("/arm_controller/follow_joint_trajectory/goal", 1000);

    ros::Rate loop_rate(10);
    
    //ros loop
    while (ros::ok()){
        control_msgs::FollowJointTrajectoryActionGoal ctrlMsg;
        ctrlMsg.goal.trajectory.joint_names.push_back("shoulder_pan_joint");
        ctrlMsg.goal.trajectory.joint_names.push_back("shoulder_lift_joint");
        ctrlMsg.goal.trajectory.joint_names.push_back("elbow_joint");
        ctrlMsg.goal.trajectory.joint_names.push_back("wrist_1_joint");
        ctrlMsg.goal.trajectory.joint_names.push_back("wrist_2_joint");
        ctrlMsg.goal.trajectory.joint_names.push_back("wrist_3_joint");

        ctrlMsg.goal.trajectory.points.resize(1);
        ctrlMsg.goal.trajectory.points[0].positions.resize(6);
        ctrlMsg.goal.trajectory.points[0].positions[0]= 0.7;
        ctrlMsg.goal.trajectory.points[0].positions[1]= -0.3;
        ctrlMsg.goal.trajectory.points[0].positions[2]= -0.3;
        ctrlMsg.goal.trajectory.points[0].positions[3]= -0.1;
        ctrlMsg.goal.trajectory.points[0].positions[4]= 0.2;
        ctrlMsg.goal.trajectory.points[0].positions[5]= -0.3;        
        // Velocities
        ctrlMsg.goal.trajectory.points[0].velocities.resize(6);
        for (size_t jointNo=0; jointNo<6;jointNo++)
            ctrlMsg.goal.trajectory.points[0].velocities[jointNo] = 0.0;
        ctrlMsg.goal.trajectory.points[0].time_from_start = ros::Duration(1.0);

        ctrlPub.publish(ctrlMsg);
    
        ros::spinOnce();
        
        loop_rate.sleep();
    }
    
    return 0;
}

