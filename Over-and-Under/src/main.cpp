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

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen

// define your global instances of motors and other devices here


void drivercontrol(){

}

int main() {
//everything gets called from here, this is the only main method call like so
    task(eftl::gui::Handler(0, 0));
    Brain.Screen.pressed(eftl::gui::Handler(Brain.Screen.xPosition(), Brain.Screen.yPosition())); // When the brain is touched, the coordinates of the touch are refered back to the GUI handler;
}