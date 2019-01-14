#include<ros/ros.h>
#include<problem9/problem9_msg.h>
#include<problem9/state_machine.h>
#include<cstdlib>

using namespace std;

int Random20() {int data = rand() % 20 + 1; return data; }
int NextState() {int Nstate = rand() % 4; return Nstate;}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "statemachine_node");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<problem9::problem9_msg>("topic9",50);
    ros::Publisher pub_state = nh.advertise<problem9::state_machine>("topic_state",1000);
    problem9::problem9_msg msg;
    problem9::state_machine msgST;

    srand(time(NULL));
    int Rnum1, Rnum2, NextSt;
    //ros::Rate loop_rate(50);
    ros::Rate loop_rate(1);
    msg.state_sum = false; msg.state_sub = false; msg.state_mul = false; msg.state_div = false;
    while(ros::ok()){
        loop_rate.sleep();
        Rnum1 = Random20(); Rnum2 = Random20(); NextSt = NextState();
        msgST.x = Rnum1; msgST.y = Rnum2; msgST.Next = NextSt;
        pub_state.publish(msgST);

        msg.a = Rnum1; msg.b = Rnum2;
        if(NextSt == 0){ msg.state_sum = true; }
        else if(NextSt == 1){ msg.state_sub = true; }
        else if(NextSt == 2){ msg.state_mul = true; }
        else if(NextSt == 3){ msg.state_div = true; }
        pub.publish(msg);

        msg.state_sum = false; msg.state_sub = false; msg.state_mul = false; msg.state_div = false;
    }
    return 0;
}