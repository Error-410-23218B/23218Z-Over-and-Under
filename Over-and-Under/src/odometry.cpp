    //odometry.cpp
    #define _USE_MATH_DEFINES
    #include "vex.h"
    #include <math.h>
    #include <array>
    #include "odometry.h"
    using namespace std;

    // Objects
    const double sL = 5.0;
    const double sR = 5.0;

eftl::Odometry::Odometry(long double encoder)
    {
        encoderDeg = encoder;
        encoderDelta = encoderDeg - prevEncoder;
        prevEncoder = encoderDeg;
    }

    eftl::Odometry EncoderLeft(1.0);
    eftl::Odometry EncoderRight(2.0);
    eftl::Odometry EncoderBack(3.0);

array<double,2> eftl::Odometry::tracking()
    {

        // Tracking Algorithm, calculates absoulute position of robot on field.
        // Vectors, first index is x value, second index is y value.
        array<double, 2> polarCoordinates;
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

        if (deltaAbsOrientation == 0)
        {
            localOffset[0] = EncoderBack.encoderDeg;
            localOffset[1] = EncoderRight.encoderDeg;
        }
        else
        {
            localOffset[0] = 2 * sin((deltaAbsOrientation / 2) * (EncoderLeft.encoderTravel / deltaAbsOrientation) + EncoderBack.encoderTravel);
            localOffset[1] = (EncoderRight.encoderDeg / deltaAbsOrientation) + EncoderRight.encoderTravel;
        }

        averageOrientation = -averageOrientation - prevAbsOrientation + (deltaAbsOrientation / 2);

        // Conversion of vectors from Cartesian Coordinates(Normal) to Polar Coordinates
        polarCoordinates[0] = sqrt(pow(localOffset[0], 2) + pow(localOffset[1], 2)); // cartesian:x gets turned into polar: r
        polarCoordinates[1] = atan(localOffset[1] / localOffset[0]);                 // cartesian:y gets turned into polar:θ
        polarCoordinates[0] = -(0.75 * M_PI);                                        // Rotate globalOffset by the negative of the average orientation, by changing polar:r

        // Conversion back of vectors from Polar Coordinates to Cartesian coordinates
        globalOffset[0] = polarCoordinates[0] * cos(globalOffset[1]);
        globalOffset[1] = polarCoordinates[0] * sin(globalOffset[1]);

        for (int i = 0; i < 2; i++)
            absoulutePosition[i] = prevGlobalOffset[i] + globalOffset[i];

        prevGlobalOffset = globalOffset;

        return absoulutePosition;
    }

int eftl::Odometry::trackingCallback()
    {
        tracking();
        return 0;
    }
