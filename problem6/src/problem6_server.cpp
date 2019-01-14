#include<ros/ros.h>
#include<problem6/problem6_srv.h>
#include<cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#define PATH_MAX 1024

//char *getcwd(char *buf, size_t size);

using namespace std;

bool SrvCallback(problem6::problem6_srv::Request& req, problem6::problem6_srv::Response& res){
    char cwd[PATH_MAX];
    if(req.checkRequest){
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            ROS_INFO("Request : %d", req.checkRequest);
            ROS_INFO("Current working dir: %s", cwd);
            res.checkResponse = req.checkRequest;
            ROS_INFO("Response : %d", res.checkResponse);
        }else {
            ROS_INFO("getcwd() error");
            res.checkResponse = false;
            exit(1);
        }
    }else{
        ROS_INFO("Request : false!");
        ROS_INFO("Closing server....");
        exit(1);
    }
    return true;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem6_server");
    ros::NodeHandle nh;
    ros::ServiceServer problem6_srv_server = nh.advertiseService("problem6_topic",SrvCallback);

    ROS_INFO("ready problem6 server!");
    ros::spin();
    return 0;
}