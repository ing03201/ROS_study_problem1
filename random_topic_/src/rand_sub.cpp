#include<ros/ros.h>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<math.h>
#include"random_topic_/topMsg.h"

using namespace std;

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v){
    out << "{";
    size_t last = v.size() - 1;
    for(size_t i = 0; i <v.size(); ++i){
        out<<pow(v[i],2);
        if(i != last)
        out << ", ";
    }
    out << "}";
    return out;
}

void callback(const random_topic_::topMsg::ConstPtr& msg){
     ROS_INFO_STREAM(" "<< msg->i);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "random_topic_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("topic", 10, callback);
    ros::spin();
    return 0;
}