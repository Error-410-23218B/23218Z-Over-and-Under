#include "vex.h"
#include "kalmanFilter.h"

using namespace vex;

double eftl::kalmanFilter::predict(){
    state = F * prevState

    dx = prevState.velocity * time_step;
    pos = prevState.pos +dx;
    var = prevState.var + process_var;
    return pos,var;

}


double eftl::kalmanFilter::update(){
    
    residual = measurement - state;
    kalman_gain =  var/(var+measurement_var);
    new_state = state + kalman_gain;
    new_var = (1- kalman_gain) * state.var;
    return new_state,new_var
}

void eftl::kalmanFilter::kalmanIterate(){
    for (int time_step;time_step < 20; time_step++){
        predict_state,predict_state.var= predict();
        new_state,new_state.var = update();
    }


}

double eftl::kalmanFilter::multiply(){
    double mean1,covariance1 = gauss1;
    double mean2,covariance2 = gauss2;

    double mean = pow(covariance2 * (covariance1 +covariance2),-1)*mean1 + covariance1 * pow((covariance1 + covariance2),-1) * mean2;
    double covariance = covariance1 * pow(( covariance1 + covariance2),-1) * covariance2;

    return mean,covariance;  
}



