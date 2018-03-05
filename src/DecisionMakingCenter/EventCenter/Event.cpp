#include "Event.h"
#include <Arduino.h>

Event::Event(){

};

void Event::setNumber(int number)
{
    this->number = number;
};

int Event::getNumber()
{
    return this->number;
};

/**
 * Опрос сенсоров для генерирования события
 */
bool Event::analizSensors()
{
    for (int i = 0; i < this->countLogic; i++)
    {
        if (this->logic[i](this))
        {
            return true;
        }
    }

    return false;
};

void Event::setSensor(Sensor *sensor)
{
    if (!this->countSensors)
    {
        this->sensors[0] = sensor;
        this->countSensors++;

        return;
    }

    Sensor **temp = new Sensor *[this->countSensors];

    memcpy(temp, this->sensors, this->countSensors * sizeof(Sensor));
    delete[] this->sensors;

    this->sensors = new Sensor *[this->countSensors + 1];
    memcpy(this->sensors, temp, sizeof(Sensor) * this->countSensors);
    delete[] temp;

    this->sensors[this->countSensors] = sensor;
    this->countSensors++;
};

void Event::addLogic(bool (*logic)(Event *event))
{
    this->logic = (bool (**)(Event * event)) realloc(this->logic, (this->countLogic + 1) * sizeof(bool (*)(Event * event)));
    this->logic[this->countLogic] = logic;
    this->countLogic++;
};

Sensor *Event::getSensor(int number)
{
    if (this->sensors[number])
    {
        return this->sensors[number];
    } 

    return;
}
