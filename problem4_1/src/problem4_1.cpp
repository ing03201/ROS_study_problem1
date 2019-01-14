#include<ros/ros.h>
#include<problem4_1/problem4_1.h>
#include<string>
#include<fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem4_1_node");
    ros::NodeHandle nh;
    ros::Publisher problem4_1_pub = nh.advertise<problem4_1::problem4_1>("problem4_1_topic",1000);
    problem4_1::problem4_1 msg;

    fstream fs("/home/choi/choi/number.txt");
    long int Cnum = 0;
    string str;
    ros::Rate loop_rate(100);
    while(fs >> str)
    {
        msg.i.push_back(str);
        Cnum++;
        loop_rate.sleep();
    }
    msg.ArrCount = Cnum;

    problem4_1_pub.publish(msg);
    for(int num = 0; num < msg.ArrCount ; num++){
        ROS_INFO_STREAM(msg.i[num]);
    }
    
    return 0;
}
