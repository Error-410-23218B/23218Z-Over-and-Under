//odometry.h
#include <array>

namespace eftl{
class Odometry{
    public:
        long double encoderTravel;
        long double encoderDeg; 
        long double encoderDelta;
        long double prevEncoder;
Odometry(long double  encoder);
static std::array<double,2> tracking();
static  int trackingCallback();
};
}