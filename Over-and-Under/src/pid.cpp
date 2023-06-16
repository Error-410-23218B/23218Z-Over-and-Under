#include "pid.h"

eftl::PIDController::PIDController(double ikP, double ikI, double ikD, double ikF)
{
  kP = ikP;
  kI = ikI;
  kD = ikD;
  kF = ikF;

  
}

double eftl::PIDController::step(double isetpoint, double process_variable)
{ 

  double error = isetpoint - process_variable;
  integral += error;
  if(integral>isetpoint){
    integral = 0;
     
  }
  derivative = error - prevError;
  prevError = error;
  Power = isetpoint * kF + error * kP + integral * kI + derivative * kD;

return Power;
  




}