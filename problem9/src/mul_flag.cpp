#include<ros/ros.h>
#include<string>
#include<problem9/problem9_msg.h>
#include<problem9/state_machine.h>
#include<cstdlib>

void callback_mul(const problem9::problem9_msg::ConstPtr& msg){
    if(msg->state_mul){ 
        ROS_INFO("sending MUL_state, data is %d",msg->a * msg->b) ;
        ros::NodeHandle mul;
        ros::Publisher mul_pub = mul.advertise<problem9::state_machine>("topic9_1",1000);
        problem9::state_machine msg2;
        msg2.Now = 2;
        mul_pub.publish(msg2);
    }
   // else{ ROS_INFO("state is not mul"); }
}

int main(int argc, char *argv[])
{
    //ros::Rate loop_rate(10);
    //loop_rate.sleep();
    ros::init(argc, argv, "mul_node");
    ros::NodeHandle nh;
    ros::Subscriber mul_sub = nh.subscribe("topic9", 50, callback_mul);
    ros::spin();    
    return 0;
}