
class Odometry
public:
    float encoderDeg;
    float encoderTravel =   2 * M_PI * encoderDelta; 
    float encoderDelta;
    float prevEncoder;