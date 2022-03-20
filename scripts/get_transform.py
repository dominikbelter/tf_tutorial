#!/usr/bin/env python3  
import roslib
roslib.load_manifest('tf_tutorial')
import rospy
import math
import tf
import geometry_msgs.msg
import tf2_msgs.msg
import turtlesim.srv

if __name__ == '__main__':
    rospy.init_node('tf_listener')

    listener = tf.TransformListener()
    listener.waitForTransform('/base_link', '/gripper', rospy.Time(), rospy.Duration(4.0))
    
    rate = rospy.Rate(10.0)
    while not rospy.is_shutdown():
        try:
            (trans,rot) = listener.lookupTransform('/base_link', '/gripper', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            continue

        print(trans)
        print(rot)

        rate.sleep()
