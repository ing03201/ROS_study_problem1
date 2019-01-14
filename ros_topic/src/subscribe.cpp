#include<ros/ros.h>
#include<ros_topic/Message.h>


void cb(const ros_topic::Message::ConstPtr& ptr){
    int sub;
    sub = ptr->data * ptr->data2;
    ROS_INFO("receive data sub = %d", sub);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ros_topic_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("TopicMsg", 1000, cb);
    ros::spin();
    return 0;
}