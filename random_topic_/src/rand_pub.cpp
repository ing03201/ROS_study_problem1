#include<ros/ros.h>
#include<cstdlib>
#include<vector>
#include"random_topic_/topMsg.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "random_topic_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<random_topic_::topMsg>("topic",10);
    random_topic_::topMsg msg;
    srand(time(NULL));
    long int randnum;
    long int num;
    int count = 0;
    
    ros::Rate loop_rate(10);
    while(ros::ok()){
        randnum = rand() % 20 + 1;
        msg.num = randnum;
        msg.i.assign(randnum, 0);
       // msg.i[rand];
        for(int a = randnum; a > 0 ; a--){
            num = rand()% 20 + 1;
            msg.i[count] = num;
            count++;
        }
        pub.publish(msg);
        count = 0;
        loop_rate.sleep();
    }   
    return 0;
}