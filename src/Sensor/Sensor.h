class Sensor
{
  private:
    int data;
    int (*call)();
    bool (*logic)(int data);

  public:
    Sensor(int (*call)(), bool (*logic)(int data));
    int getData();
    bool callSensorHandler(int data);

};