#include <ros/ros.h>
#include <unistd.h>
#include "problem6/problem6_srv.h"
bool function(problem6::problem6_srv::Request &req, problem6::problem6_srv::Response &res){
    char cwd[PATH_MAX];
    if(getcwd(cwd, sizeof(cwd))!= NULL){
        res.result = cwd;
        ROS_INFO("Current working dir : %s\n", res.result.c_str());
    }
    else{
        ROS_ERROR("getcwd() error");
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem6_server");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("problem6", function);
    /* code for main function */
    ROS_INFO("ready to Request!");

    ros::spin();
    return 0;
}