#pragma once

#include "../Platform/Movement/Legs4.h"
#include "./EventCenter/EventGenerator.h"
#include "./Behavior/Behavior.h"
#include "./BehaviorEventRelation/BehaviorEventRelation.h"

class DecisionMakingCenter
{
  private:
    int countSensors = 0;                    // кол-во сенсоров
    Legs4 *platform;                         // Палтформа передвижения
    EventGenerator *eventGenerator;          // Генератор событий
    Behavior **behavior;                     // Массив поведений
    int countBehavior = 0;                   // Кол-во добавленных поведений
    Relation **behaviorEventRelation; // массив структур для описания связи события и соответствующего ему поведения
    int countBehaviorRelation = 0;           // Кол-во связей
    void saveBehaviorRelation(Behavior *behavior);

  public:
    DecisionMakingCenter(
        Legs4 *platform,
        EventGenerator *eventGenerator);

    EventGenerator getEventGenerator();
    void addBehavior(Behavior *behavior, Event *event);
    void addBehavior(Behavior *behavior);
    void addBehaviorRelation(Event *event, Behavior *behavior);
};