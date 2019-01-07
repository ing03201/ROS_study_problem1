#include <ros/ros.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string> 

using namespace std;

int main(int argc, char **argv){
    ros::init(argc, argv, "problem4");
    fstream is;
    int k;
    std::vector<int> v;
    is.open("problem4_in.txt");
    if(is.fail()){
        ROS_ERROR("File is none");
    }
    else{
        while(is >> k){
            v.push_back(k);
        }
        is.close();
        fstream fs("problem4_out.txt");
        std::vector<int>::iterator i;
        for(i = v.begin(); i != v.end(); i++){
            fs << -(*i) << endl;
            ROS_INFO_STREAM(*i);
        }
        fs.close();
    }
    return 0;

}