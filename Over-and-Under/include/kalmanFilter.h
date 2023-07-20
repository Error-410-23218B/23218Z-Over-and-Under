//kalmanFilter.h
#pragma once
#ifndef kalmanFilter_h
#define kalmanFilter_h


struct kalmanFilter
{
    double velocity;
    double pos;
    double var;
}prev_state;



namespace eftl{
    class kalmanFilter
    {
    public:
        double measurement;
        double state;
        double PROCESS_VAR = 0.1;
        double MEASUREMENT_VAR = 0.1;
        double TIME_STEP = 0.01;
        double new_state;
        double new_var;
        double predict_state;
        double predict_var;
        double kalman_gain;
        double residual;
        double variance;
        double F[3][3] = {{1,deltaTime,0.5*pow(deltaTime,2)},
                          {0,1,deltaTime},
                          {0,0,1}}
        double Q[4][4]={{0,0.001,0,0},
                        {0.001,0.001,0,0},
                        {0,0,0,0.001},
                        {0,0,0.001,0.001}}
        kalmanFilter();
        double predict();
        double update();
        double multiply(double gauss,double gauss2);
      
    };
   
}

#endif