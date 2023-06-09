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
float prevEncoderDelta;
float encoderDistanceDelta = EncoderLeft.encoderTravel + EncoderRight.encoderTravel;
float absOrientation = encoderDistanceDelta + (EncoderLeft.encoderTravel - EncoderRight.encoderTravel);


}


Odometry EncoderLeft(5.0);
Odometry EncoderRight(6.0);

