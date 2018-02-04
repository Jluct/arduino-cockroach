#include "DecisionMakingCenter.h"

DecisionMakingCenter::DecisionMakingCenter(Legs4 *platform, EventGenerator *eventGenerator)
{
    this->platform = platform;
    this->eventGenerator = eventGenerator;
}
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
}