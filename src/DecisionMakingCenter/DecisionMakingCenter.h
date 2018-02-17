#pragma once

#include "../Platform/Movement/Legs4.h"
#include "./EventCenter/EventGenerator.h"
#include "./Behavior/Behavior.h"
#include "./BehaviorEventRelation/BehaviorEventRelation.h"

class DecisionMakingCenter
{
  private:
    int countSensors = 0;           // кол-во сенсоров
    Legs4 *platform;                // Палтформа передвижения
    EventGenerator *eventGenerator; // Генератор событий
    Behavior **behavior;
    int countBehavior = 0;
    struct Relation **behaviorEventRelation;

  public:
    DecisionMakingCenter(
        Legs4 *platform,
        EventGenerator *eventGenerator);

    EventGenerator getEventGenerator();
    void addBehavior(Behavior *behavior, int event = 0);
    void addBehaviorRelation(Event *event, Behavior *behavior);
};