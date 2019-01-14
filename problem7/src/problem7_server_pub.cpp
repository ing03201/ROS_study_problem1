#include<ros/ros.h>
#include<string>
#include<fstream>
#include<problem7/problem7_srv.h>
#include<problem7/problem7_msg.h>

using namespace std;

bool Callback(problem7::problem7_srv::Request& req, problem7::problem7_srv::Response& res){
    problem7::problem7_msg msg;
    ros::NodeHandle nh2;
    ros::Publisher pub = nh2.advertise<problem7::problem7_msg>("topic7",1000);
    ROS_INFO_STREAM(req.Fullpath);
    //const string st = req.Fullpath;
    fstream fs(req.Fullpath.c_str());
    // char 
    string ss;
    int count = 0;

    ros::Rate loop_rate(1000);
    while(fs >> ss){
        res.state = false;
        count++;
        msg.str.push_back(ss);
        loop_rate.sleep();
        ROS_INFO("server is working...");
    }
    for(int i = 0; i < count; i++){
        ROS_INFO_STREAM(msg.str[i]);
    }
    res.state = true;
    pub.publish(msg);
    ROS_INFO("DONE!");
    return true;
}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem7_server_publisher");
    ros::NodeHandle nh;
    //ros::Publisher pub = nh.advertise<problem7::problem7_msg>("topic7",1000);
    ros::ServiceServer server = nh.advertiseService("problem7_service",Callback);

    ros::spin();
    return 0;
}