#include "vex.h"
#include "kalmanFilter.h"

double eftl::kalmanFilter::predict(){


    dx = prevState.velocity * time_step;
    state.pos = prevState.pos +dx;
    state.var = prevState.var + process_var;
    return state.pos,state.var;

}


double eftl::kalmanFilter::update(){
    double residual;
    double kalman_gain;
    residual = measurement - state;
    kalman_gain =  var/(var+measurement_var);
    new_state = state + kalman_gain;
    new_state.var = (1- kalman_gain) * state.var;
    return new_state,new_var
}

void eftl::kalmanFilter::kalmanIterate(){
    for (int time_step;time_step < 20; time_step++){
        predict_state,predict_state.var= predict();
        new_state,new_state.var = update();
    }
    
}


