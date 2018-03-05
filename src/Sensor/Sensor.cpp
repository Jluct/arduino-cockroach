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

/**
 *  Вызов метода считывания показания датчика
 *  Если датчик вызывается чаще определённого интервала
 *  то возвращаются ранее сохранённые данные
 */
int Sensor::request()
{
    long int currentTime = millis();
    if ((currentTime - this->lastCall) < this->validTime)
    {
        return this->data;
    }
    this->lastCall = currentTime;

    return this->data = this->call();
};