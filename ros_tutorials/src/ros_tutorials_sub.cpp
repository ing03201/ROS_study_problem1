#include<ros/ros.h>
#include<std_msgs/Bool.h>

/*/ void boolcb(const ros_tutorials::MessageFileNmae::ConstPtr& msg)
//  {
        ROS_INFO("recieved %d",ptr->data);
    }

    int mai(int argc, char** argv)
    {
        ros::init(argc, argv, "ros_tutorials_sub");
        ros::NodeHandle nh;
        ros::Subscriver sub = nh.subscriber("TopicName",10,boolcb);

        ros::spin();

        return 0;
    }
*/
void boolcb(const std_msgs::Bool::ConstPtr& ptr){
    ROS_INFO("received %d", ptr->data);

}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "ros_tutorials_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("simple_bool", 10, boolcb);
    
    ros::spin();
    return 0;
}
