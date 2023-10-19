#include "vex.h"
#include<math>
#include <array>
class ramseteController{
    public:
    double k;
    double v;
    double actual;
    double desired;
    array<double,3> transformMatrix; 
        array<double,2> angularVelocityVector;
        array<double,2 linearVelocityVector;
    double B,Damp,LinVeloc,AngVeloc;
    ramseteController(double iB, double iDamp, double pLinVeloc, double pAngVeloc ):  B(iB), Damp(iDamp),LinVeloc(pLinVeloc),AngVeloc(pAngVeloc){

    }


    array<double,2> matrixIterate(array<double,2> paramArray){
        for (int i = 0; i < sizeof(paramArray/double); i++)
        {
            paramArray[i] +=  ; 
        }
        return paramArray;
    }

    void ramseteCalculate(){
       array<double,2> tempArray;
       angularVelocityVector = {2,AngVeloc};
       linearVelocityVector = {2,LinVeloc}
       tempArray[0] = B * LinVeloc[0];
       tempArray[1] = B * LinVeloc[1];
       transformMatrix = {{cos(actual),sin(actual),0},{-sin(actual),cos(actual),0},{0,0,1}}
       k = 2*Damp*sqrt(angularVelocityVector + tempArray);
       v = angularVelocity[1] * cos(actual);
    }

}