#include "ros/ros.h"
#include <gazebo_msgs/ModelStates.h>
#include <gazebo_msgs/SetModelState.h>
#include <geometry_msgs/Pose.h>
int main(int argc, char **argv)
{
    ros::init(argc, argv, "init1");

    ros::NodeHandle n;
    
    geometry_msgs::Pose init_pose;
    init_pose.position.x = 2.0;
    init_pose.position.y = 1.0;
    init_pose.position.z = 0.0;
    init_pose.orientation.x = 0.0;
    init_pose.orientation.y = 0.0;
    init_pose.orientation.z = 0.0;
    init_pose.orientation.w = 0.0;
    
    gazebo_msgs::ModelState modelstate;
    modelstate.model_name = (std::string) "tb3_0";
    modelstate.pose = init_pose;
    
    ros::ServiceClient client = n.serviceClient<gazebo_msgs::SetModelState>("/gazebo/set_model_state");
    
    gazebo_msgs::SetModelState setmodelstate;
    setmodelstate.request.model_state = modelstate;
    client.call(setmodelstate);

    return 0;
}
