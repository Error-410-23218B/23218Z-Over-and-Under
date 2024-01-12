#define _USE_MATH_DEFINES
#include "vex.h"
#include <vector>
#include <cmath>
#include "odometry2.h"
purdue 





odometry2::odometry2(double wheel_radius): wheelRadius(wheel_radius)
{}

odometry2::~odometry2()
{}

odometry2::reset(Encoder encoderReset){

    current = encoderReset;
    desired = encoderReset;

}



 void reset(Encoder encoderReset,double angle){

    reset(encoderReset);
    double heading = angle * M_PI/180.0;
    double prev_heading = heading;
    double desired_heading = heading;

 }

inline odometry2::step(Encoder encoderVal){
 
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

    else
    {
            localOffset[0],localOffset[1] = (difference.backEncoder/changeInGlobalOrientation) + backToCenter, (difference.rightEncoder/changeInGlobalOrientation)+rightToCenter;
            localOffset[0],localOffset[1] *= (2 * sin(absouluteOrientation/2));
    }

    averageOrientation = prevGlobalOrientation + (changeInGlobalOrientation/2);
    double localOffsetPolar[2] = {hypot(localOffset[0],localOffset[1]), atan(((double)localOffset[1]/localOffset[0]))};
    localOffset[1] -= averageOrientation;
    globalOffset[0],globalOffset[1] = localOffsetPolar[0] * cos(localOffset[1]),localOffsetPolar[0] * sin(localOffset[1]);
    absoulutePosition[0],absoulutePosition[1] = prevAbsoulutePosition[0] + globalOffset[0], prevAbsoulutePosition[1] + globalOffset[1];
    prevAbsoulutePosition[0],prevAbsoulutePosition[1] = absoulutePosition[0],absoulutePosition[1];

    return absoulutePosition;
 
}

