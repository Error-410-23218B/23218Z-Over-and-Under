/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Administrator                                             */
/*    Created:      12/05/2023, 16:17:06                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "odometry.h"
#include "pid.h"
#include "drivetrain.h"
#include "gui.h"
#include "autonomous.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen

// define your global instances of motors and other devices here


void drivercontrol(){
    Drivetrain.setVelocity(100,percent);
    puncher.setVelocity(100);
    climber.setVelocity(100);
}



void handlerCallback(){
    Handler();
}

int main() {
//everything gets called from here, this is the only main method call like so
    handlerCallback();
    Brain.Screen.released(handlerCallback);// When the brain is touched, the coordinates of the touch are refered back to the GUI handler;
    task tracking(eftl::Odometry::trackingCallback,15);
    Competition.autonomous(autonomous);
    Competition.drivecontrol(drivercontrol);
     
    }