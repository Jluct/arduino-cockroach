#include "Sensor.h"
#include <Arduino.h>

Sensor::Sensor(int (*call)())
{
    this->call = call;
};

int Sensor::getData()
{
    return this->data;
};

int Sensor::request()
{
    if ((millis() - this->lastCall) < this->validTime)
    {
        return this->data;
    }
    return this->data = this->call();
    
};