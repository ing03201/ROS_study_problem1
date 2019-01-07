#include <ros/ros.h>
#include <unistd.h>
#include "problem7/problem7_srv.h"
#define PATH_MAX 100

using namespace std;

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem7_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<problem7::problem7_srv>("problem7");
    
    problem7::problem7_srv srv;
    if(client.call(srv)){
        srv.request.fpath = "/home/kim/catkin_ws/problem7/problem7.txt";
        srv.request.direct = "/home/kim/catkin_ws/problem7";
    }
    else{
        ROS_ERROR("Failed to call problem7");
    }
    return 0;
}