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
competition Competition;
// A global instance of vex::brain used for printing to the V5 brain screen

// define your global instances of motors and other devices here





void handlerCallback(){
    Handler();
}

void pneum(){
    DigitalOutH.set(true);
    DigitalOutG.set(true);
}

void pneumF(){
    DigitalOutH.set(false);
    DigitalOutG.set(false);
}

void drivercontrol(){
   
    Controller.ButtonR1.pressed(pneum);
    Controller.ButtonR2.pressed(pneumF);
}


int main(){  
    Drivetrain.setDriveVelocity(100,percent);
    puncher.setVelocity(100,percent);
    climber.setVelocity(100,percent); 
    task rc_auto_loop_function_Controller1(rc_auto_loop_function_Controller1);
//everything gets called from here, this is the only main method call like so
    handlerCallback();
    Brain.Screen.released(handlerCallback);// When the brain is touched, the coordinates of the touch are refered back to the GUI handler;
    task tracking(eftl::Odometry::trackingCallback,15);
    Competition.drivercontrol(drivercontrol);
    Competition.autonomous(autonomous);
    return 1;
}