#if !defined DecisionMakingCenter

#include "../Platform/Movement/Legs4.h"
#include "./EventCenter/EventGenerator.h"

class DecisionMakingCenter
{
  private:
    int countSensors = 0;           // кол-во сенсоров
    Legs4 *platform;                // Палтформа передвижения
    EventGenerator *eventGenerator; // Генератор событий

  public:
    DecisionMakingCenter(
        Legs4 *platform,
        EventGenerator *eventGenerator);

    EventGenerator getEventGenerator();
};

#endif