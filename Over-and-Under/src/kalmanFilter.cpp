// #include "vex.h"
// #include "kalmanFilter.h"
// #include "math.h"
// #include <array>

// eftl::kalmanFilter::kalmanFilter() {
//     predict_state,predict_var =  predict();
//     new_state,new_var = update();
// }

// double eftl::kalmanFilter::predict(){
//     state = F * prev_state + B * u;
//     variance = F * variance * F_transposed + Q;
//     double dx = prev_state.velocity * TIME_STEP;
//     double pos = prev_state.pos + dx;
//     double var = prev_state.var + PROCESS_VAR;
//     return pos,var
// }

// double eftl::kalmanFilter::update(){
//     double y = z - H * state;
//     K = P * H_transpose * pow((H*P*H_transpose + R),-1)
//     state = prev_state + K * y;
//     variance = (I-K*H)*P;
//     residual = measurement - state;
//     kalman_gain = var / (var + MEASUREMENT_VAR);
//     new_state = state + kalman_gain
//     new_var = (1- kalman_gain) * var
// }

// double eftl::kalmanFilter::multiply(double gauss,double gauss2){
//     double mean1,covariance1 = gauss;
//     double mean2,covariance2 = gauss2;
//     double mean = covariance2 * pow((covariance1 + covariance2),-1) * mean1 + covariance1 * pow((covariance1 + covariance2),-1) * mean2;
//     double covariance = covariance1 * pow((covariance1 + covariance2),-1) * covariance2;
//     return mean,covariance 
// }