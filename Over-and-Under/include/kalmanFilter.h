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
        kalmanFilter();
        double predict();
        double update();
        double multiply(double gauss,double gauss2);
      
    };
   
}

#endif