#include<ros/ros.h>
#include<string>
#include<problem9/problem9_msg.h>
#include<problem9/state_machine.h>
#include<cstdlib>

void callback_div(const problem9::problem9_msg::ConstPtr& msg){
    if(msg->state_div){ 
        ROS_INFO("sending DIV_state, data is %2f",(float)msg->a / (float)msg->b) ;
        ros::NodeHandle di;
        ros::Publisher di_pub = di.advertise<problem9::state_machine>("topic9_1",1000);
        problem9::state_machine msg2;
        msg2.Now = 3;
        di_pub.publish(msg2);
    }
    //else{ ROS_INFO("state is not div"); }
}

int main(int argc, char *argv[])
{
    //ros::Rate loop_rate(10);
    //loop_rate.sleep();
    ros::init(argc, argv, "div_node");
    ros::NodeHandle nh;
    ros::Subscriber div_sub = nh.subscribe("topic9", 50, callback_div);
    ros::spin();    
    return 0;
}