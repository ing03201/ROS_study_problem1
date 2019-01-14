#include<ros/ros.h>
#include"problem5/message.h"
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "problem5_pub_node");
    ros::NodeHandle nh;
    ros::Publisher problem5_pub = nh.advertise<problem5::message>("topic_problem5",1000);
    problem5::message msg;

    fstream fs;
    fs.open("/home/choi/choi/number.txt");
   // int fd = open("/home/choi/choi/number.txt");
    int count=0;
    long int tmp;

    ros::Rate loop_rate(10);
    //while(ros::ok()){

    while (fs >> tmp){
        msg.i.push_back(tmp);
        count++;
        ROS_INFO_STREAM(count);
        loop_rate.sleep();
    }
    fs.close();
    msg.vNum = count;
    problem5_pub.publish(msg);
        //loop_rate.sleep();

    //}
    /*while (fs >> tmp){
        msg.i.push_back(tmp);
        count++;
        ROS_INFO_STREAM(count);
        loop_rate.sleep();
    }
    fs.close();
    msg.vNum = count;
    problem5_pub.publish(msg);*/

    return 0;
}

/*
if(o<(fd = open("asdasasdda",O_RDONLY)))
{
    read(fd, buff, size);
    put(buff);
    close(fd);
}
*/