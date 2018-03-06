#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#include "DecisionMakingCenter.h"
#include "./BehaviorEventRelation/BehaviorEventRelation.h"

EventGenerator *DecisionMakingCenter::getEventGenerator()
{
    return this->eventGenerator;
};

DecisionMakingCenter::DecisionMakingCenter(Legs4 *platform, EventGenerator *eventGenerator)
{
    this->platform = platform;
    this->eventGenerator = eventGenerator;
};

void DecisionMakingCenter::callBehavior()
{
    for (int i = 0; this->eventGenerator->getCountActiveEvent(); i++)
    {
        this->eventGenerator->getActiveEvents()[i]->callBehavior(0);
    }
};

void DecisionMakingCenter::testSituation()
{
    this->eventGenerator->eventsAnalis();
};