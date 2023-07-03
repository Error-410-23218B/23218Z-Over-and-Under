class Odometry{
    public:
        float encoderTravel;
        float encoderDeg; 
        float encoderDelta;
        float prevEncoder;
Odometry::Odometry(float encoder);
};