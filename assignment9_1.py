#!/usr/bin/env python3
#chmod u+x ~/catkin_ws/src/beginner_msgsrv/src/assignment9_1.py
import rospy 
import rospkg 
from gazebo_msgs.msg import ModelState 
from gazebo_msgs.srv import SetModelState

nodename = 'tb3_0'
rospy.init_node('init2', anonymous=True)

stage_msg = ModelState()
stage_msg.model_name = nodename
stage_msg.pose.position.x = 1
stage_msg.pose.position.y = 1
stage_msg.pose.position.z = 0
stage_msg.pose.orientation.x = 0
stage_msg.pose.orientation.y = 0
stage_msg.pose.orientation.z = 0
stage_msg.pose.orientation.w = 0

rospy.wait_for_service('/gazebo/set_model_state')

set_state = rospy.ServiceProxy('/gazebo/set_model_state',SetModelState)

resp = set_state(stage_msg)

