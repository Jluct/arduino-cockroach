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

void DecisionMakingCenter::saveBehaviorRelation(Behavior *behavior)
{
    this->behavior = (Behavior **)realloc(this->behavior, (this->countBehavior + 1) * sizeof(Behavior));
    behavior->setNumber(this->countBehavior);
    this->behavior[this->countBehavior] = behavior;
    this->countBehavior++;
};

void DecisionMakingCenter::addBehaviorRelation(Event *event, Behavior *behavior)
{
    struct Relation relation = {event, behavior};
    this->behaviorEventRelation = (Relation **)realloc(this->behaviorEventRelation, (this->countBehaviorRelation + 1) * sizeof(Relation));
    this->behaviorEventRelation[this->countBehaviorRelation] = &relation;
    this->countBehaviorRelation++;
};

void DecisionMakingCenter::addBehavior(Behavior *behavior, Event *event)
{
    this->saveBehaviorRelation(behavior);
    this->addBehaviorRelation(event, behavior);
};

void DecisionMakingCenter::addBehavior(Behavior *behavior)
{
    this->saveBehaviorRelation(behavior);
};

void DecisionMakingCenter::callBehavior()
{

};