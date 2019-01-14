#include<ros/ros.h>
#include<problem6/problem6_srv.h>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem6_client");
    if(argc != 2){
        ROS_INFO("Sevice Server is not working");
        return 1;
    }
    ros::NodeHandle nh;
    ros::ServiceClient problem6_srv_client = nh.serviceClient<problem6::problem6_srv>("problem6_topic");
    problem6::problem6_srv srv;
    
    srv.request.checkRequest = atoll(argv[1]);
    problem6_srv_client.call(srv);
    return 0;
}