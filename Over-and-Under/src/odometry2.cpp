#include "vex.h"
#include <vector>



class odometry2
{
protected:
        struct Encoder
        {
            double leftEncoder,
            double rightEncoder,
            double backEncoder
        };
Encoder current;
Encoder prev;
Encoder difference;
Encoder reset;
        


private:
double leftToCenter;
double rightToCenter;
double backToCenter;
double deltaOrientation;

vector<double> prevGlobalPositionVector;
vector<double> prevGlobalOrientation;
vector<double> prevGlobalOrientationAtLastReset;
    /* data */
public:
    odometry2(/* args */);
    ~odometry2();
    step();
};

odometry2::odometry2(/* args */)
{
}

odometry2::~odometry2()
{
}

odometry2::step(){
    difference = current - prev;
    deltaOrientation = (difference.leftEncoder - difference.rightEncoder)/(leftToCenter+rightToCenter);
    prev = current;
    
}

