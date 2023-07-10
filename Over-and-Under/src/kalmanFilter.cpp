//kalmanFilter.cpp
#include "vex.h"
#include "kalmanFilter.h"

double eftl::kalmanFilter::predict(){
    state = F * prevState + B * u;
    variance = F * variance * F_transposed + q;

    dx = prevState.velocity * time_step;
    pos = prevState.pos +dx;
    var = prevState.var + process_var;
    return pos,var;

}


double eftl::kalmanFilter::update(){
    y = z - H * state;
    K = P * pow (H_transpose * (H*PH*H_transpose + R),-1);

    state = prev_states + K * y;
    variance = (I-K*H) * P;
    

    double residual;
    double kalman_gain;
    residual = measurement - state;
    kalman_gain =  var/(var+measurement_var);
    new_state = state + kalman_gain;
    new_state.var = (1- kalman_gain) * state.var;
    return new_states,new_state.var
}

void eftl::kalmanFilter::kalmanIterate(){
    for (int time_step;time_step < 20; time_step++){
        predict_states,predict_state.var= predict();
        new_states,new_state.var = update();
    }


}

double eftl::kalmanFilter::multiply(double gauss3, double gauss4){
    double mean1,covariance1 = gauss1;
    double mean2,covariance2 = gauss2;

    double mean = pow(covariance2 * (covariance1 +covariance2),-1)*mean1 + covariance1 * pow((covariance1 + covariance2),-1) * mean2;
    double covariance = covariance1 * pow(( covariance1 + covariance2),-1) * covariance2;

    return mean,covariance;  
}


