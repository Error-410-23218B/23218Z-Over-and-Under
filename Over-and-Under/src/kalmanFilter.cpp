#include "vex.h"
#include "tgmath.h"
#include "kalmanFilter.h"



eftl::kalmanFilter::kalmanFilter() {
    predict_state,predict_var =  predict();
    new_state,new_var = update();
}

eftl::kalmanFilter::predict(){
    double dx = prev_state.velocity * TIME_STEP;
    double pos = prev_state.pos + dx;
    double var = prev_state.var + PROCESS_VAR;
    return pos,var
}

eftl::kalmanFilter::update(){
    residual = measurement - state;
    kalman_gain = var / (var + MEASUREMENT_VAR);
    new_state = state + kalman_gain
    new_var = (1- kalman_gain) * var
}

eftl::kalmanFilter::multiply(double gauss,double gauss2){
    double mean1,covariance1 = gauss;
    double mean2,covariance2 = gauss2;
    double mean = covariance2 * pow((covariance1 + covariance2),-1) * mean1 + covariance1 * pow((covariance1 + covariance2),-1) * mean2;
    double covariance = covariance1 * pow((covariance1 + covariance2),-1) * covariance2;
    return mean,covariance 
}