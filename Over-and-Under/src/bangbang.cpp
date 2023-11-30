#include "vex.h"

class bangbang
{
private:
    /* data */
    double threshold;
    double sensorValue;
    double analogSensorValue;

public:
    bangbang(double Threshold, double sensor_value);
    step();
    ~bangbang();
};

bangbang::bangbang(double Threshold, double sensor_value,double analog_sensor_value): threshold(Threshold),sensorValue(sensor_value),analogSensorValue(analog_sensor_value)
{
    sensorValue = get(analogSensorValue);

}

bangbang::~bangbang()
{
}

bangbang::step(void (*on_pointer),void (*off_pointer)){
    while(1)
    {
    
        if (sensorValue < threshold)
        {
            on_pointer();
        }

        else{
            off_pointer();
        }
    }
    wait(20,msec);
}
     