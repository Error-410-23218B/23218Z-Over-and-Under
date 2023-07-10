//kalmanFilter.h
namespace eftl{
    struct kalmanFilterVar
    {
        double velocity;
        double pos;
        double var;

    }prevState,predict_state,new_state;
    
    
    class kalmanFilter{
        public:
                double variance;
                double new_states;
                double prev_states;
                double y;
                double K;
                double predict_states;
                double pos;
                double var;
                double state;
                double pos;
                double var;
                double state;
                const double process_var = 0.1;
                const double measurement_var = 0.1;
                const double time_step = 0.01;
                double dx;
                double gauss1;
                double gauss2;

             
 
                double predict();
                double update();
                void kalmanIterate();
                double multiply(double gauss3,double gauss4);
                

    };
}