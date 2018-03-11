#pragma once

#include "../Platform/Movement/Legs4.h"
#include "./EventCenter/EventGenerator.h"
#include "./Behavior/Behavior.h"
#include "DecisionMakingCenter/Situation/Situation.h"

class DecisionMakingCenter
{
  private:
    int countSensors = 0;           // Кол-во сенсоров
    Legs4 *platform;                // Платформа передвижения
    EventGenerator *eventGenerator; // Генератор событий

    struct Situation **situation;
    int countSituation = 0;

    int getActualSituation();

  public:
    DecisionMakingCenter(
        Legs4 *platform,
        EventGenerator *eventGenerator);

    EventGenerator *getEventGenerator();

    void testSituation();
    void callBehavior();
    void addSituation(Situation *situation);
};