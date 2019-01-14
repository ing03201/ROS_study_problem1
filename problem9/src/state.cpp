#include<ros/ros.h>
#include<problem9/problem9_msg.h>
#include<problem9/state_machine.h>
#include<cstdlib>

void callback1(const problem9::state_machine::ConstPtr& msg){
    if(msg->Now == 0){ ROS_INFO("Now state = SUM"); }
    else if(msg->Now == 1){ ROS_INFO("Now state = SUB"); }
    else if(msg->Now == 2){ ROS_INFO("Now state = MUL"); }
    else if(msg->Now == 3){ ROS_INFO("Now state = DIV"); }
}

void callback2(const problem9::state_machine::ConstPtr& msg2){
    if(msg2->Next == 0){ ROS_INFO("Next state = SUM, NEXT X=%d Y=%d", msg2->x, msg2->y); }
    else if(msg2->Next == 1){ ROS_INFO("Next state = SUB, NEXT X=%d Y=%d", msg2->x, msg2->y); }
    else if(msg2->Next == 2){ ROS_INFO("Next state = MUL, NEXT X=%d Y=%d", msg2->x, msg2->y); }
    else if(msg2->Next == 3){ ROS_INFO("Next state = DIV, NEXT X=%d Y=%d", msg2->x, msg2->y); }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "state");
    ros::NodeHandle nh;
    ros::Subscriber sub1 = nh.subscribe("topic9_1", 1000, callback1);
    ros::Subscriber sub2 = nh.subscribe("topic_state", 1000, callback2);

    ros::spin();
    return 0;
}