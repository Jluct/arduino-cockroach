#pragma once

#include "../Platform/Movement/Legs4.h"
#include "./EventCenter/EventGenerator.h"
#include "./Behavior/Behavior.h"
#include "./BehaviorEventRelation/BehaviorEventRelation.h"
#include "DecisionMakingCenter/Situation/Situation.h"

class DecisionMakingCenter
{
  private:
    int countSensors = 0;                // Кол-во сенсоров
    Legs4 *platform;                     // Палтформа передвижения
    EventGenerator *eventGenerator;      // Генератор событий
    
    unsigned long int *currentSituation; // Текущая ситуация. Каждое сработка события или НЕ сработка увеличивает/уменьшает счётчик типов ситуации

    int getActualSituation();

  public:
    DecisionMakingCenter(
        Legs4 *platform,
        EventGenerator *eventGenerator);

    EventGenerator *getEventGenerator();

    void addBehaviorRelation(Event *event, Behavior *behavior);

    void testSituation();
    void callBehavior();
};