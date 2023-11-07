#include "vex.h"
#include <math>
#include <array>
#include <vector>
class ramseteController
{
public:
    double k;

    double v;

    double actual;

    double desired;

    double omega;

    double omegaDesired;

    double linearDesired;

    const double wheelCircumference = 5;
    array<double, 3> error;
    array<double, 3> transformMatrix;
    array<double, 3> desiredMatrix;
    array<double, 3> differentialMatrix;
    array<double, 2> angularVelocityVector;
    array<double, 2> linearVelocityVector;
    double left;
    double right;
    double B, Damp, LinVeloc, AngVeloc,x;

    ramseteController(double iB, double iDamp, double pLinVeloc, double pAngVeloc) : B(iB), Damp(iDamp), LinVeloc(pLinVeloc), AngVeloc(pAngVeloc)
    {}

    array<double, 2> matrixIterate(array<double, 2> paramArray)
    {
        for (int i = 0; i < sizeof(paramArray / sizeof(double)); i++)
        {
            paramArray[i] += cos();
        }
        return paramArray;
        
    }

    void ramseteCalculate()
    {

        error = {{xdesired - }};
        array<double, 2> tempArray;
        angularVelocityVector = {2, AngVeloc};
        linearVelocityVector = {2, LinVeloc} tempArray[0] = B * LinVeloc[0];
        tempArray[1] = B * LinVeloc[1];

        transformMatrix = { {cos(actual), sin(actual), 0},
                            {-sin(actual), cos(actual), 0},
                            {0, 0, 1} 
                            };
         differntialMatrix = { {cos(actual), sin(actual), 0},
                                {-sin(actual), cos(actual), 0},
                                {0, 0, 1} };
        error[0] = transformMatrix[0] * differentialMatrix[0];
        error[1] = transformMatrix[1] * differentialMatrix[1];
        error[2] = transformMatrix[2] * differentialMatrix[2];
        k = 2 * Damp * sqrt(angularVelocityVector + tempArray);
        v = angularVelocity[1] * cos(actual);
        LinVeloc = v / wheelCircumference;

        omega = omegaDesired + k * error[2] + ((B * linearDesired * sin(error[2]) * error[1]) / error[2]);
        left = LinVeloc + AngVeloc;
        right = LinVeloc - AngVeloc;

    }
}