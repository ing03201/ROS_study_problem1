#include<ros/ros.h>
#include<string>
#include<cstdlib>
#include"problem3_2/message1.h"
#include"problem3_2/message.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem_pub_node");
    ros::NodeHandle nh;
    ros::Publisher pub1 = nh.advertise<problem3_2::message>("topic1",1000);
    ros::Publisher pub2 = nh.advertise<problem3_2::message1>("topic2",1000);

    problem3_2::message msg1;
    problem3_2::message1 msg2;

    srand(time(NULL));

    ros::Rate loop_rate(10);

    while(ros::ok()){
        msg1.first = rand() % 20 + 1;
        msg2.second = rand() % 20 + 1;
        pub1.publish(msg1);
        pub2.publish(msg2);
        loop_rate.sleep();
    }

    return 0;
}