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
    Drivetrain.setDriveVelocity(100,percent);
    puncher.setVelocity(100,percent);
    climber.setVelocity(100,percent);
    Controller1.ButtonR1.pressed(pneumaticsT);
    Controller1.ButtonR2.pressed(pneumaticsOff);
}

void pneumaticsT(){DigitalOutG.set(true);DigitalOutH.set(true);}
void pneumaticsOff(){DigitalOutG.set(false);DigitalOutH.set(false);}



int main() {
    vexcodeInit();
    // task tracking(eftl::Odometry::trackingCallback,15);
    task GUI(GUIHandler);
    Competition.autonomous(autonomous);
    Competition.drivercontrol(drivercontrol);
     return 0;
    }