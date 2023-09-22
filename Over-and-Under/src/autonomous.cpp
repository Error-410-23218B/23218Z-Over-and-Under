#include "vex.h"
#include "autonomous.h"
#include "gui.h"

void autonomous(){
    basicAuton()
}

void basicAuton(){
    Drivetrain.driveFor(100,mm);
    Drivetrain.turnFor(right,90,degrees);
    Drivetrain.driveFor(forward,30,mm);
    Drivetrain.driveFor(reverse,30,mm);
    Drivetrain.turnFor(right,180,degrees)
    
    
}
void shoot(){
    
}
void skillAuton(){
    shoot();
    Drivetrain.driveFor(reverse,100,mm);
    Drivetrain.turnFor(90,degrees,right);
    Drivetrain.driveFor(50,mm);
    Drivetrain.driveFor(right,90,degrees);
    Drivetrain.driveFor(300,mm);
}

