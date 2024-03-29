//customDrivetrain.cpp
#include "vex.h"
#include "pid.h"
#include "drivetrain.h"
#include <math>
#include "stdlib.h"
#include <iostream>
#define extern M_PI
using namespace vex;
const double pi = 3.1415926535;

eftl::PIDController LeftDrive(0.0, 0.0, 0.0, 0.0);
eftl::PIDController RightDrive(0.0, 0.0, 0.0, 0.0);
eftl::PIDController LeftTurn(0.0, 0.0, 0.0, 0.0);
eftl::PIDController RightTurn(0.0, 0.0, 0.0, 0.0);
eftl::PIDController DrivePos(0.0, 0.0, 0.0, 0.0);

eftl::customDrivetrain::customDrivetrain(vex::motor_group &l, vex::motor_group &r, double wheelTravel, double trackWidth, double wheelBase, vex::distanceUnits unit, double externalGearRatio)
{

    deg_mm = (pi * wheelBase) / 360;
    trn_mm = (trackWidth * pi) / 180;
    task a1(velocTR);
};

long double eftl::customDrivetrain::slew(double input)
{

    time_t start, end;
    double slst = time(&start);
    double slewLastInput;
    double output;
    double desired_change;
    double clamped_increase = desired_change;
    output = slewLastInput + clamped_increase;
    slewLastInput = output;
    double max_increase = slst / 10;
    desired_change = input - slewLastInput;

    double slen = time(&end);
    double sl = slen - slst;
    return output;
}

void eftl::customDrivetrain::setVelocity(double veloc)
{
    Velocity = veloc;
}

int eftl::customDrivetrain::velocTR()
{
    while (true)
    {

        eftl::customDrivetrain::VelocL = LeftDrive.step(slew(Velocity), DrivetrainLeft.voltage(voltageUnits::mV));
        eftl::customDrivetrain::VelocR = RightDrive.step(slew(Velocity), DrivetrainRight.voltage(voltageUnits::mV));
    }
    return 0;
}

void eftl::customDrivetrain::spin()
{
    DrivetrainLeft.spin(forward, eftl::customDrivetrain::VelocL, voltageUnits::mV);
    DrivetrainRight.spin(forward, eftl::customDrivetrain::VelocR, voltageUnits::mV);
}

void eftl::customDrivetrain::spinFor(double spinPos, vex::directionType direction)
{

    DrivetrainLeft.spinFor(direction, DrivePos.step(spinPos / deg_mm, DrivetrainLeft.position(deg)), rotationUnits::deg);
    DrivetrainRight.spinFor(direction, DrivePos.step(spinPos / deg_mm, DrivetrainLeft.position(deg)), rotationUnits::deg);
}

void eftl::customDrivetrain::stop()
{
    DrivetrainLeft.stop();
    DrivetrainRight.stop();
}

void eftl::customDrivetrain::turnFor(vex::turnType turnVar, double turnAmount)
{

    if (turnVar == vex::turnType::left)
    {

        DrivetrainLeft.spinFor(forward, LeftDrive.step((DrivetrainLeft.position(degrees) + turnAmount) / trn_mm, DrivetrainLeft.position(degrees)), degrees);
        DrivetrainRight.spinFor(reverse, (RightDrive.step((DrivetrainRight.position(degrees) + turnAmount / trn_mm), DrivetrainRight.position(degrees))), degrees);
    }

    if (turnVar == vex::turnType::right)
    {
        DrivetrainLeft.spinFor(reverse, LeftDrive.step((DrivetrainLeft.position(degrees) + turnAmount / trn_mm), DrivetrainLeft.position(degrees)), degrees);
        DrivetrainRight.spinFor(forward, (RightDrive.step((DrivetrainRight.position(degrees) + turnAmount / trn_mm), DrivetrainRight.position(degrees))), degrees);
    }
}

void eftl::customDrivetrain::odometricMotion()
{
    
    double distance;
    double angle;
    array<double,2> position Odometry::tracking();
    distance = sqrt(pow(position[0],2)+pow(position[1],2));
    
}
