#define _USE_MATH_DEFINES
#include "vex.h"
#include <vector>
#include <cmath>


namespace eftl
{
class odometry2
{
protected:
struct Encoder
        {
            double leftEncoder;
            double rightEncoder;
            double backEncoder;



Encoder getHeading(bool radians) const{
    if(true){
        return this;
    }
    else{
    return {
        leftEncoder * 180/M_PI,
        rightEncoder * 180/M_PI,
        backEncoder * 180/M_PI
    };
    }
}




Encoder operator-(const Encoder& other) const
    {
        return {
            leftEncoder - other.leftEncoder,
            rightEncoder - other.rightEncoder,
            backEncoder - other.backEncoder
        };
    }

Encoder operator+(const Encoder& other) const
    {
        return {
            leftEncoder + other.leftEncoder,
            rightEncoder + other.rightEncoder,
            backEncoder + other.backEncoder
        };
    }

      Encoder operator*(double operand) const
    {
        return {
            leftEncoder * operand,
            rightEncoder * operand,
            backEncoder * operand
        };
    }

       Encoder operator/(double operand) const
    {
        return {
            leftEncoder / operand,
            rightEncoder / operand,
            backEncoder / operand
        };
    }



};

Encoder current;
Encoder prev;
Encoder difference;
Encoder reset;
Encoder wheelDistance;
Encoder lastResetDistance;
Encoder skid;
Encoder desired; 



private:
    double leftToCenter;
    double rightToCenter;
    double backToCenter;
    double deltaOrientation;
    double wheelRadius;

    double absouluteOrientation;
    double prevGlobalOrientation;
    double prevGlobalOrientationAtLastReset;
    double changeInGlobalOrientation;
    double averageOrientation;


    std::vector<double> prevGlobalPositionVector;
    double localOffset[2];
    double globalOffset[2];
    double absoulutePosition[2];
    double prevAbsoulutePosition[2];
public:
    odometry2(double wheel_radius);
    ~odometry2();
    void step(Encoder encoderVal);
    void reset(Encoder encoderReset);
    void reset(Encoder encoderReset,double angle);

};
}
