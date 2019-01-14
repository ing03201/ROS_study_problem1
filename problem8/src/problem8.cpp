#include<cstdlib>
#include<ros/ros.h>
#include<problem8/problem8_msg.h>

int ERROR = 999999;

class State{
public:
    State(int x, int y){
        if(x == 0){ state =  0; data = data + y; }
        else if(x == 1) { state = 1; data = data - y; }
        else if(x == 2) { state = 2; data = data * y; }
        else if(x == 3) { state = 3; data = data / y; }
        else { ROS_INFO("state is not 0, 1, 2, 3 "); }
    }
    State(int x, int y, int z){
        if(x == 0){ state =  0; data = y + z; }
        else if(x == 1) { state = 1; data = y - z; }
        else if(x == 2) { state = 2; data = y * z; }
        else if(x == 3) { state = 3; data = y / z; }
        else { ROS_INFO("state is not 0, 1, 2, 3 "); }
    }
    int data = 0;

private:
    int state;
};

int StateMachine(){ int st = rand() % 4; return st; }
int RandNum(){ int Rnum = rand() % 20 + 1; return Rnum; }

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "problem8_pub_node");
    ros::NodeHandle nh;
    ros::Publisher problem8_pub = nh.advertise<problem8::problem8_msg>("topic8",10);
    problem8::problem8_msg msg;

    srand(time(NULL));
    int Ndata = 0;
    int x_ = rand() % 20 + 1;
    int y_ = rand() % 20 + 1;
    int rState = 0;
    //State ST(rState, x_, y_);
    ros::Rate loop_rate(50);
    while(ros::ok()){
        //Ndata = ST(rState, x_, y_).data;
        State* St = new State(rState, x_, y_);
        Ndata = St->data;
        msg.Num = Ndata;
        problem8_pub.publish(msg);
        ROS_INFO("state = %d, X=%d Y=%d ,data = %d", rState, x_, y_, Ndata);
        x_ = RandNum(); y_ = RandNum();
        loop_rate.sleep();
        rState = StateMachine();
        delete St;
    }
    return 0;
}