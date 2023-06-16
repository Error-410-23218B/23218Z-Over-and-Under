#define _USE_MATH_DEFINES
#include "vex.h"
#include <math.h>
#include <array>
using namespace std;

const float sL = 5.0;
const float sR = 5.0;

class Encoding
{
public:
    float encoderDeg;
    float encoderTravel = 2 * M_PI * encoderDelta;
    float encoderDelta;
    float prevEncoder;
    Encoding(float encoder)
    {

        encoderDeg = encoder;
        encoderDelta = encoderDeg - prevEncoder;
        prevEncoder = encoderDeg;
    }
};

// Tracking Algorithm, calculates absoulute position of robot on field.
void tracking()
{
    // Vectors, first index is x value, second index is y value.
    array<double, 2> globalOffset;
    array<double, 2> localOffset;
    array<double, 2> prevGlobalOffset;
    array<double, 2> absoulutePosition;

    float prevAbsOrientation;
    float prevEncoderDelta;
    float encoderDistanceDelta = EncoderLeft.encoderTravel + EncoderRight.encoderTravel;
    float absOrientation = encoderDistanceDelta + ((EncoderLeft.encoderTravel - EncoderRight.encoderTravel) / (sL + sR));
    float deltaAbsOrientation = absOrientation - prevAbsOrientation;
    prevAbsOrientation = absOrientation;
    float averageOrientation;
    float localOffset = 2 * sin(deltaAbsOrientation / 2);

    // If the left side distance change = right side distance change.

    if (deltaAbsOrientation == 0)
    {

        localOffset[0] = EncoderBack.encoderTravel;
        localOffset[1] = EncoderRight.encoderTravel;
    }
    // else if left side distance change != right side distance change.

    else
    {
        localOffset[0] = 2 * sin((deltaAbsOrientation / 2) * (EncoderLeft.encoderTravel / deltaAbsOrientation) + EncoderBack.encoderTravel);
        localOffset[1] = (EncoderRight.encoderDeg / deltaAbsOrientation) + EncoderRight.encoderTravel;
    }

    averageOrientation = prevAbsOrientation + (deltaAbsOrientation / 2);

    // Conversion of vectors from Cartesian Coordinates(Normal) to Polar Coordinates
    globalOffset[0] = sqrt(pow(localOffset[0], 2) + pow(localOffset[1], 2)); // cartesian:x gets turned into polar: r
    globalOffset[1] = atan(localOffset[1] / localOffset[1]);                 // cartesian:y gets turned into polar:θ
    globalOffset[0] = -averageOrientation - (0.75 * M_PI);                   // Rotate globalOffset by the negative of the average orientation, by changing polar:r

    // Conversion back of vectors from Polar Coordinates to Cartesian coordinates
    globalOffset[0] = globalOffset[0] * cos(globalOffset[1]);
    globalOffset[1] = globalOffset[0] * sin(globalOffset[1]);

    for (int i = 0; i < 2; i++)
        absoulutePosition[i] = prevGlobalOffset[i] + globalOffset[i];

    prevGlobalOffset = globalOffset;
}

Encoding EncoderLeft(1.0);
Encoding EncoderRight(2.0);
Encoding EncoderBack(3.0);
