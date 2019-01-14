#include<ros/ros.h>
#include<string>
#include<problem9/problem9_msg.h>
#include<problem9/state_machine.h>
#include<cstdlib>

void callback_sum(const problem9::problem9_msg::ConstPtr& msg){
    if(msg->state_sum){ 
        ROS_INFO("sending SUM_state, data is %d",msg->a + msg->b) ;
        ros::NodeHandle sum;
        ros::Publisher sum_pub = sum.advertise<problem9::state_machine>("topic9_1",1000);
        problem9::state_machine msg2;
        msg2.Now = 0;
        sum_pub.publish(msg2);
    }
    //else{ ROS_INFO("state is not sum"); }
}

int main(int argc, char *argv[])
{
    //ros::Rate loop_rate(10);
    //loop_rate.sleep();
    ros::init(argc, argv, "sum_node");
    ros::NodeHandle nh;
    ros::Subscriber sum_sub = nh.subscribe("topic9", 50, callback_sum);
    ros::spin();    
    return 0;
}