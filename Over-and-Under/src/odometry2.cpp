#define _USE_MATH_DEFINES
#include "vex.h"
#include <vector>
#include <cmath>




class odometry2
{
protected:
        struct Encoder
        {
            double leftEncoder;
            double rightEncoder;
            double backEncoder;



Encoder radToDeg() const{
    return {
        leftEncoder * 180/M_PI,
        rightEncoder * 180/M_PI,
        backEncoder * 180/M_PI
    };
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
    void reset();
};



odometry2::odometry2(double wheel_radius): wheelRadius(wheel_radius)
{}

odometry2::~odometry2()
{}

odometry2::reset(){}

inline void odometry2::step(Encoder encoderVal){
    difference = encoderVal - prev;
    wheelDistance = (difference.radToDeg()/360) * (2 * M_PI * wheelRadius);
    deltaOrientation = (difference.leftEncoder - difference.rightEncoder)/(leftToCenter+rightToCenter);
    prev = encoderVal;
    lastResetDistance = ((skid - encoderVal).radToDeg()/360) * (2 * M_PI * wheelRadius);
    absouluteOrientation = prevGlobalOrientationAtLastReset + (lastResetDistance.leftEncoder - lastResetDistance.rightEncoder) / (leftToCenter + rightToCenter);
    changeInGlobalOrientation = absouluteOrientation - prevGlobalOrientation;

    if (changeInGlobalOrientation == 0)
    {
        localOffset[0],localOffset[1] = difference.backEncoder,difference.rightEncoder;
    }
    else{
        localOffset[0],localOffset[1] = (difference.backEncode  r/changeInGlobalOrientation) + backToCenter, (difference.rightEncoder/changeInGlobalOrientation)+rightToCenter;
        localOffset[0],localOffset[1] *= (2 * sin(absouluteOrientation/2));
}
    averageOrientation = prevGlobalOrientation + (changeInGlobalOrientation/2);
    double localOffsetPolar[2] = {hypot(localOffset[0],localOffset[1]), atan(((double)localOffset[1]/localOffset[0]))};
    localOffset[1] -= averageOrientation;
    globalOffset[0],globalOffset[1] = localOffsetPolar[0] * cos(localOffset[1]),localOffsetPolar[0] * sin(localOffset[1]);
    absoulutePosition[0],absoulutePosition[1] = prevAbsoulutePosition[0] + globalOffset[0], prevAbsoulutePosition[1] + globalOffset[1];
    prevAbsoulutePosition[0],prevAbsoulutePosition[1] = absoulutePosition[0],absoulutePosition[1];
}

