#pragma once

class Sensor
{
  private:
    int data = 0;
    unsigned long lastCall = 0;
    unsigned int validTime = 100;
    int (*call)();

  public:
    Sensor(int (*call)());
    int getData();
    int request();
};