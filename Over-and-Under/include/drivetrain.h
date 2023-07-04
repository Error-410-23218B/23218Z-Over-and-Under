#pragma once
#ifndef drivetrain_h
#define drivetrain_h
#include "vex.h"

typedef signed char directionType;
typedef signed char turnType;

namespace eftl{
class customDrivetrain{
    public:
       static double Velocity;
       static double VelocL;
       static double VelocR;
       double deg_mm;
       double trn_mm;
       
    
    customDrivetrain(vex::motor_group &l, vex::motor_group &r, double wheelTravel = 320, double trackWidth = 320, double wheelBase = 130, vex::distanceUnits unit = vex::distanceUnits::mm, double externalGearRatio = 1.0);
    static double slew(double input);   
    void spin();
    void  setVelocity(double veloc);
    static int velocTR();
    void stop();
    void turnFor(vex::turnType turnvar,double turnAmount);
    void spinFor(double spinPos,vex::directionType direction);
    void odometricMotion();
    
};



}
#endif