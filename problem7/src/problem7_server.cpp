#include <ros/ros.h>
#include <unistd.h>
#include <fstream>
#include "problem7/problem7_srv.h"
#include "problem7/problem7_msg.h"

using namespace std;

class problem7_class{
    public:
    problem7_class(){
        server = nh.advertiseService("problem7", &problem7_class::srvcallback, this);
    }

    bool srvcallback(problem7::problem7_srv::Request& req,problem7::problem7_srv::Response& res){
        pub = nh.advertise<problem7::problem7_msg>("problem7",1000);
        ros::Rate loop_rate(1000);
        fs.open(req.fpath.c_str());
        string s;
        ROS_ERROR("we cannot receive request!!");
        while(fs >> s){
            msg.c.push_back(s);
            ROS_INFO_STREAM(s);
            loop_rate.sleep();
        }
        //debugging line
        for(size_t i = 0; i < msg.c.size(); i++){
            ROS_INFO_STREAM(msg.c[i]);
        }
        pub.publish(msg);
        ROS_INFO("Finish!!");
        return true;
    }
    private:
        ros::NodeHandle nh;
        ros::Publisher pub;
        ros::ServiceServer server;
        problem7::problem7_msg msg;
        problem7::problem7_srv srv;
        fstream fs;
};

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem7_server");
    problem7_class k;
    ros::spin();
    return 0;
}