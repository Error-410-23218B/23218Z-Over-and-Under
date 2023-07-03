#define _USE_MATH_DEFINES
#include "vex.h"
#include <math.h>
#include <array>
#include "odometry.h"
using namespace std;

//add class here for all 3 encoders.
/*
int trackingAlgorithm(){
float prevEncoderVal;
float encoderDegL = FrontEncoderA.get();
float encoderDegR = FrontEncoderB.get();
float encoderValL = 2 * M_PI * encoderDegL;
float encoderValR = 2 * M_PI * encoderDegR;
float encoderValDeltaL   = encoderValL - prevEncoderVal;
 prevEncoderVal = encoderValL;



return 0;
}
*/
//Objects
const float sL= 5.0;
const float sR= 5.0;






    Odometry::Odometry(float encoder){
        encoderDeg = encoder;
        encoderDelta = encoderDeg - prevEncoder; 
        prevEncoder = encoderDeg;

    }



int tracking(){
array<double,2> globalOffset;
array<double,2> localOffset;
array<double,2>prevGlobalOffset;
array<double,2>absoulutePosition;
float prevAbsOrientation;
float prevEncoderDelta;
float encoderDistanceDelta = EncoderLeft.encoderTravel + EncoderRight.encoderTravel;
float absOrientation = encoderDistanceDelta + ((EncoderLeft.encoderTravel - EncoderRight.encoderTravel)/(sL+sR));
float deltaAbsOrientation = absOrientation - prevAbsOrientation;
prevAbsOrientation = absOrientation;
float averageOrientation;
float deltaAbsOrientation = 2 * sin(deltaAbsOrientation/2);


if(deltaAbsOrientation == 0){
localOffset[0] =  EncoderBack.encoderDeg;
localOffset[1] = EncoderRight.encoderDeg;


}
else{
    localOffset[0] = 2 * sin((deltaAbsOrientation/2)* (EncoderLeft.encoderTravel/deltaAbsOrientation) +  EncoderBack.encoderTravel);
    localOffset[1] = (EncoderRight.encoderDeg/deltaAbsOrientation) + EncoderRight.encoderTravel;
}

 averageOrientation = prevAbsOrientation + (deltaAbsOrientation/2);
 globalOffset[0] = sqrt(pow(localOffset[0],2) + pow(localOffset[1],2));
 globalOffset[1] = atan(localOffset[1]/localOffset[1]);
 globalOffset[0] = -averageOrientation - (0.75*M_PI);
for (int i = 0; i<2;i++) absoulutePosition[i] = prevGlobalOffset[i] + globalOffset[i];

prevGlobalOffset = globalOffset;


return 0;

}


    


Odometry EncoderLeft(1.0);
Odometry EncoderRight(2.0);
Odometry EncoderBack(3.0);

