#include<ros/ros.h>
#include<ros_topic/Message.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ros_topic");
    ros::NodeHandle nh;
    ros::Publisher ros_topic_pub = nh.advertise<ros_topic::Message>("TopicMsg",10);
    ros_topic::Message msg;

    ros::Rate loop_rate(10);
    int num1 = 0;
    int num2 = 0;
    while(ros::ok()){
        msg.data = num1;
        msg.data2 = num2;
        ROS_INFO("send int type data = %d data2 = %d", msg.data, msg.data2);
        ros_topic_pub.publish(msg);
        ++num1; ++num2;
        loop_rate.sleep();
    }
    return 0;
}