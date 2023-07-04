#pragma once
#ifndef odometry_h
#define odometry_h

#include "math.h"
namespace eftl
{
 class Odometry{
public:
    float encoderDeg;
    float encoderTravel =   2 * M_PI * encoderDelta; 
    float encoderDelta;
    float prevEncoder;
Odometry(float encoder);
static int tracking();

};
}

#endif odometry_h