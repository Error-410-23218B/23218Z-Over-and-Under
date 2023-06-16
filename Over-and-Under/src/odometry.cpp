#include "vex.h"
#include <cmath>
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




//The class is here.
class Odometry{


public:
    float encoderDeg;
    float encoderTravel =   2 * M_PI * encoderDelta; 
    float encoderDelta;
    float prevEncoder;


    Odometry(float encoder){

        encoderDeg = encoder;
        encoderDelta = encoderDeg - prevEncoder; 
        prevEncoder = encoderDeg;


    }




};

void tracking(){
float localOffset[2];
float prevAbsOrientation;
float prevEncoderDelta;
float encoderDistanceDelta = EncoderLeft.encoderTravel + EncoderRight.encoderTravel;
float absOrientation = encoderDistanceDelta + ((EncoderLeft.encoderTravel - EncoderRight.encoderTravel)/(sL+sR));
float deltaAbsOrientation = absOrientation - prevAbsOrientation;
prevAbsOrientation = absOrientation;
float averageOrientation;
float localOffset = 2 * sin(deltaAbsOrientation/2);
if(deltaAbsOrientation == 0){



}
else{
    localOffset[0] = 2 * sin((deltaAbsOrientation/2)* (EncoderLeft.encoderTravel/deltaAbsOrientation) +  EncoderBack.encoderTravel);
    localOffset[1] = (EncoderRight.encoderDeg/deltaAbsOrientation) + EncoderRight.encoderTravel;




}

 averageOrientation = prevAbsOrientation + (deltaAbsOrientation/2);
 

}


Odometry EncoderLeft(1.0);
Odometry EncoderRight(2.0);
Odometry EncoderBack(3.0);

