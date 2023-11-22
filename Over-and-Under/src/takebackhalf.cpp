class takebackhalf
{
private:
    double TBHInit;
    double TBHActual;
    double Gain;
    double Error;
    double Reductor;
public:
    takebackhalf(double tbhActual, double tbhInitital,double gain,double error,double reductor );
    ~takebackhalf();
    void step();
};

takebackhalf::takebackhalf(double tbhActual, double tbhInitital,double gain,double error,double reductor): 
TBHActual(tbhActual),
TBHInit(tbhInitital),
Gain(gain),
Error(error)
{}

takebackhalf::~takebackhalf()
{
 
}

void takebackhalf::step(){
    if (Error<0){
            TBHActual -= Reductor;
        }
        

}