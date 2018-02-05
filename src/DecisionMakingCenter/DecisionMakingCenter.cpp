#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#include "DecisionMakingCenter.h"

DecisionMakingCenter::DecisionMakingCenter(Legs4 *platform, EventGenerator *eventGenerator)
{
    this->platform = platform;
    this->eventGenerator = eventGenerator;
};

void DecisionMakingCenter::scanningSpace()
{
    if (this->sensors[this->currentSensor]->getData())
    {
        this->eventGenerator->hasActiveEvent = true;
    }

    if ((this->countSensors - 1) == this->currentSensor)
    {
        this->currentSensor = 0;
        return;
    }

    this->currentSensor++;
};

void DecisionMakingCenter::setSensor(Sensor *sensor)
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