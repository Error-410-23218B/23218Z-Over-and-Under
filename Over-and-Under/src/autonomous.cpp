#include "vex.h"
#include "autonomous.h"
#include "gui.h"

void autonomous(){
    basicAuton()
}

void basicAuton(){
    Drivetrain.driveFor(10,cm);
    Drivetrain.turnFor(right,90,degrees);
    Drivetrain.driveFor(forward,3,cm);
    Drivetrain.driveFor(reverse,3,cm);
    Drivetrain.turnFor(right,180,degrees)
    
    
}