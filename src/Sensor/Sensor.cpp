#include "Sensor.h"
#include <Arduino.h>

Sensor::Sensor(int (*call)())
{
    this->call = call;
};

/**
 * Deprecatet 
 */
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
    unsigned long int currentTime = millis();
    Serial.println(currentTime);
    if ((currentTime - this->lastCall) < this->validTime)
    {
        return this->data;
    }
    this->lastCall = currentTime;
    this->data = this->call();
    return this->data;
};