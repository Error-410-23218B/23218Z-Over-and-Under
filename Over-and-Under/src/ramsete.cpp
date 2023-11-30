#include "vex.h"
#include "odometry.h"
#include <math>
#include <array>
#include <vector>
#include <numeric>
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
    vector<double> error;
    vector<double> transformMatrix;
    vector<double> desiredMatrix;
    vector<double> differentialMatrix;
    vector<double> angularVelocityVector;
    vector<double> linearVelocityVector;
    double left;
    double right;
    double B, Damp, LinVeloc, AngVeloc,x;
    vector<double,3> desired = {};
    vector<double,3> actual = {};
    double differential;
    double smallScalar;
    ramseteController(double iB, double iDamp, double pLinVeloc, double pAngVeloc,double small_scalar) : B(iB), Damp(iDamp), LinVeloc(pLinVeloc), AngVeloc(pAngVeloc),smallScalar(small_scalar)
    {}

    // array<double, 2> matrixIterate(array<double, 2> paramArray)
    // {
    //     for (int i = 0; i < sizeof(paramArray / sizeof(double)); i++)
    //     {
    //         paramArray[i] += cos();
    //     }
    //     return paramArray;
    // }

    void ramseteCalculate()
    {
        array<double, 2> tempArray;
        angularVelocityVector = {2, AngVeloc};
        linearVelocityVector = {2, LinVeloc} tempArray[0] = B * LinVeloc[0];
        tempArray[1] = B * LinVeloc[1];

        transformMatrix = { 
                            {cos(actual), sin(actual), 0},
                            {-sin(actual), cos(actual),0},
                            {0, 0, 1} 
                          };
         
        error = std::inner_product(transformMatrix.begin(),tranformMatrix.end(),differentialMatrix.begin(),0);
        k = 2 * Damp * sqrt(angularVelocityVector + tempArray);
        v = angularVelocity[1] * cos(actual);
        LinVeloc = v / wheelCircumference;
        angularVelocity =  ;
        omega = omegaDesired + k * error[2] + ((B * linearDesired * sin(error[2]) * error[1]) / error[2]);
        left = LinVeloc + AngVeloc;
        right = LinVeloc - AngVeloc;  
    }
}