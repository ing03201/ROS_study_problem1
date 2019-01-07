#include <ros/ros.h>

#include "problem3/problem3_msg.h"

using namespace std;

int64_t sum;
void subCallback(const problem3::problem3_msgPtr& msg){
    if(sum != 0){
        sum = 0;
        sum += msg->data;
    }
    else{
        sum += msg->data;
    }
    ROS_INFO_STREAM("first message & second message sum is " << sum);
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "problem3_sub");
    ros::NodeHandle nh;

    ros::Subscriber first = nh.subscribe("problem3", 1000, subCallback);
    ros::Subscriber second = nh.subscribe("problem3", 1000, subCallback);
    
    ros::spin();
    return 0;
}