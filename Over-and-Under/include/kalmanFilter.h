namespace eftl{
    struct kalmanFilterVar
    {
        double velocity;
        double pos;
        double var;

    }prevState,state,new_state,predict_state,measurement;
    
    
    class kalmanFilter{
        public:

                const double process_var = 0.1;
                const double measurement_var = 0.1;
                const double time_step = 0.01;
                double dx;
             
 
                double predict();
                double update();
                void kalmanIterate();
                double multiply(double ga );

    };
}