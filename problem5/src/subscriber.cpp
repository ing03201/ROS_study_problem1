#include<ros/ros.h>
#include"problem5/message.h"
#include<string>
//#include<unistd.h>
//#include<sys/types.h>
//#include<fcntl.h>
#include<fstream>

using namespace std;

void callback1(const problem5::message::ConstPtr& msg){
    fstream asd("/home/choi/choi/number2.txt");
    //asd.open("/home/choi/choi/number2.txt");
    for(int a = 0;a < msg->vNum; a++){
        asd << (-msg->i[a]) <<endl;
    }
    asd.close();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "problem5_sub_node");
    ros::NodeHandle nh;
    ros::Subscriber problem5_sub = nh.subscribe("topic_problem5",1000,callback1);
    ros::spin();
    return 0;
}
