#include <ros/ros.h>
#include<string>
#include<problem7/problem7_srv.h>
#include<problem7/problem7_msg.h>

using namespace std;

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem7_client");
    ros::NodeHandle nh;
    ros::ServiceClient problem7_srv_client = nh.serviceClient<problem7::problem7_srv>("problem7_service");
    problem7::problem7_srv srv;

    srv.request.Fullpath = "/home/choi/choi/problem7/problem7.txt";
   // ROS_INFO_STREAM(srv.request.Fullpath);
    srv.request.DestinationDirectory = "/home/choi/choi/problem7";

    problem7_srv_client.call(srv);
    return 0;
}