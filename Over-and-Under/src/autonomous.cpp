#include "vex.h"
#include "autonomous.h"
#include "gui.h"




void autonomous(){
    basicAuton();
}



void basicAuton(){
    Drivetrain.driveFor(100,mm);
    Drivetrain.turnFor(right,90,degrees);
    Drivetrain.driveFor(forward,30,mm);
    Drivetrain.driveFor(reverse,30,mm);
    Drivetrain.turnFor(right,180,degrees);
}


void skillAuton(){
    puncherMotor.spin(forward);
    wait(30000,msec);
    Drivetrain.driveFor(forward,200,mm);
    Drivetrain.turnFor(right,30,degrees);
    
}

