#include<ros/ros.h>
#include<std_msgs/Bool.h>

/*
int main(int argc, char** argv)
{
    ros::init(argc, argv, "ros_tutorials_pub");
    ros::NodeHandel nh;
    ros::Publisher pub = nh.advertise<ros_tutorials::MessageFileName>("TopicName",10);

    ros::Rate loop_rate(10);

    ros_tutorials::MessageFileName msg;

    while(ros::ok()){
        msg.data = ~msg.data;
        ROS_INFO("msg.data = %d",msg.data);
        pub.publish(msg);

        loop_rate.sleep();
    }

    return 0;
}
*/
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "ros_tutorials_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Bool>("simple_bool",10);

    ros::Rate loop_rate(10);
    std_msgs::Bool msg;
   // std_msgs::BoolConstPtr* p;
    while (ros::ok())
    {
       // ROS_INFO("",p->data);
        msg.data = ~msg.data;
        pub.publish(msg);
        loop_rate.sleep();
    }
    
    return 0;
}
