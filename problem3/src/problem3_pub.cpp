#include <ros/ros.h>
#include <cstdlib>
#include "problem3/problem3_msg.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv){
    ros::init(argc, argv, "problem3_pub");
    ros::NodeHandle nh;
    ros::Publisher first = nh.advertise<problem3::problem3_msg>(
        "problem3", 1000);
    ros::Publisher second = nh.advertise<problem3::problem3_msg>(
        "problem3", 1000);
    ros::Rate loop_rate(10);

    problem3::problem3_msg msg1;
    problem3::problem3_msg msg2;
    int count = 0;
    msg1.id = "first_message";
    msg2.id = "second message";
    srand(time(NULL));
    while(ros::ok()){
        ROS_INFO_STREAM(msg1.id <<"'s value is "<< msg1.data); 
        //cin >> msg1.data;
        msg1.data = rand() % 10;
        ROS_INFO_STREAM(msg2.id <<"'s value is "<< msg2.data);
        //cin >> msg2.data;
        msg2.data = rand() % 10;
        // ROS_INFO();
        first.publish(msg1);
        second.publish(msg2);
        count++;
        loop_rate.sleep();
    }
    return 0;

}