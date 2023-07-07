#include <array>

namespace eftl{
class Odometry{
    public:
        float encoderTravel;
        float encoderDeg; 
        float encoderDelta;
        float prevEncoder;
Odometry(float encoder);
static int tracking();
};
}