//vex.h
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;
extern brain Brain;
extern competition Competition;

extern controller Controller1;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor_group LeftDriveSmart;
extern motor rightMotorA; 
extern motor rightMotorB;
extern motor_group RightDriveSmart;
extern drivetrain Drivetrain;
extern encoder FrontEncoderA;
extern encoder BackEncoder;
extern encoder FrontEncoderB;
extern motor  leftMotorA;
extern motor  leftMotorB;
extern motor  rightMotorA;
extern motor  rightMotorB;
extern motor_group DrivetrainLeft;
extern motor_group DrivetrainRight;










#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)