#include<ros/ros.h>
#include<string>
#include<cstdlib>
#include"problem3_2/message1.h"
#include"problem3_2/message.h"

int sum = 0;
void callback1(const problem3_2::message::ConstPtr& msg1){
    sum = msg1->first + sum;
    ROS_INFO("recieve first data = %d", msg1->first);
}
void callback2(const problem3_2::message1::ConstPtr& msg2){
    sum += msg2->second;
    ROS_INFO("recieve second data = %d", msg2->second);
    ROS_INFO("SUM value is %d", sum);
    sum = 0;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem_sub_node");
    ros::NodeHandle nh;
    ros::Subscriber sub1 = nh.subscribe("topic1",1000,callback1);
    ros::Subscriber sub2 = nh.subscribe("topic2",1000,callback2);

    ros::spin();
    return 0;
}