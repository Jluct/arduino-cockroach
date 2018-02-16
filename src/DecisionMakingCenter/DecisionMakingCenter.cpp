#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#include "DecisionMakingCenter.h"

DecisionMakingCenter::DecisionMakingCenter(Legs4 *platform, EventGenerator *eventGenerator)
{
    this->platform = platform;
    this->eventGenerator = eventGenerator;
};

void DecisionMakingCenter::addBehavior(Behavior *behavior, int event)
{
    this->behavior = (Behavior **)realloc(this->behavior, this->countBehavior + 1 * sizeof(Behavior));
    behavior->setNumber(this->countBehavior);
    this->behavior[this->countBehavior] = behavior;
    this->countBehavior++;

    if(event == 0){
        return;
    }

    
}