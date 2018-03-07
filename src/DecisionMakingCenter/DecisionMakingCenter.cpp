#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#include "DecisionMakingCenter.h"
#include "./BehaviorEventRelation/BehaviorEventRelation.h"

int DecisionMakingCenter::getActualSituation(){
    return 0;
};

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
        Event *event = this->eventGenerator->getActiveEvents()[i];
        event->callBehavior(this->getActualSituation());
    }
};

/**
 * Проверка на вызов события
 * Если событие было вызвано то управление передаётся дальше
 * Если нет - уменьшаем счётчик текущей ситуации
 * 
 * TODO: Может и прогресс тут выставлять?
 * 
 */
void DecisionMakingCenter::testSituation()
{
    Event *event;
    if (!this->eventGenerator->eventsAnalis(event))
    {
        this->currentSituation[event->getType()] -= event->getRegress();
    }

    this->currentSituation[event->getType()] += event->getProgress();
};