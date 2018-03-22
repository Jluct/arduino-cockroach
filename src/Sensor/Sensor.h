#pragma once

class Sensor
{
  private:
    int data = 0;
    int lastCall = 0;
    int validTime = 100;
    int (*call)();

  public:
    Sensor(int (*call)());
    int getData();
    int request();
};