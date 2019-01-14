#include<ros/ros.h>
#include<string>
#include<problem9/problem9_msg.h>
#include<problem9/state_machine.h>
#include<cstdlib>

void callback_sub(const problem9::problem9_msg::ConstPtr& msg){
    if(msg->state_sub){ 
        ROS_INFO("sending SUB_state, data is %d",msg->a - msg->b) ;
        ros::NodeHandle sub;
        ros::Publisher sub_pub = sub.advertise<problem9::state_machine>("topic9_1",1000);
        problem9::state_machine msg2;
        msg2.Now = 0;
        sub_pub.publish(msg2);
    }
    //else{ ROS_INFO("state is not sub"); }
}

int main(int argc, char *argv[])
{
    //ros::Rate loop_rate(10);
    //loop_rate.sleep();
    ros::init(argc, argv, "sub_node");
    ros::NodeHandle nh;
    ros::Subscriber sub_sub = nh.subscribe("topic9", 50, callback_sub);
    ros::spin();    
    return 0;
}