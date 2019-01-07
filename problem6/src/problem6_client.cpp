#include <ros/ros.h>
#include <unistd.h>
#include "problem6/problem6_srv.h"

using namespace std;

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem6_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<problem6::problem6_srv>("problem6");
    
    problem6::problem6_srv srv;
    if(client.call(srv)){
        srv.request.b = true;
    }
    else{
        ROS_ERROR("Failed to call problem6");
    }

    /* code for main function */
    return 0;
}