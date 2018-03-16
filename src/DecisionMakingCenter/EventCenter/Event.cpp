#include "Event.h"
#include <Arduino.h>
#include "../Behavior/Behavior.h"

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
        Serial.println("analizSensors");
        digitalWrite(13, !digitalRead(13));
        // delay(1000);
        if (this->logic[i](this))
        {
            return true;
        }
    }

    return false;
};

void Event::callBehavior(int type, Legs4 *platform)
{
    this->behavior[type]->callBehavior(platform);
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

bool Event::getSensor(int number, Sensor *sensor)
{
    if (this->sensors[number])
    {
        sensor = this->sensors[number];
        return true;
    }

    return false;
}

void Event::setActive(bool active)
{
    this->active = active;
};

void Event::addBehavior(Behavior *behavior)
{
    this->behavior = (Behavior **)realloc(this->behavior, (this->countBehavior + 1) * sizeof(Behavior*));
    behavior->setNumber(this->countBehavior);
    this->behavior[this->countBehavior] = behavior;
    this->countBehavior++;
};

void Event::setType(int type)
{
    this->type = type;
};

int Event::getType()
{
    return this->type;
};

void Event::setProgress(int step)
{
    this->progress = step;
};

void Event::setRegress(int step)
{
    this->regress = step;
};

int Event::getProgress()
{
    return this->progress;
};

int Event::getRegress()
{
    return this->regress;
};