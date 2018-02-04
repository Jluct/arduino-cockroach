#include "Sensor.h"

Sensor::Sensor(int (*call)(), bool (*logic)(int data))
{
    this->call = call;
    this->logic = logic;
};

int Sensor::getData()
{
    return this->data;
};

bool Sensor::callSensorHandler(int data)
{
    this->data = this->call(); // не уверен в работоспособности
    return this->logic(this->data);
};