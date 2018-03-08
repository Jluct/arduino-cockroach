#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#include "DecisionMakingCenter.h"

int DecisionMakingCenter::getActualSituation()
{
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
 */
void DecisionMakingCenter::testSituation()
{
    Event *event;
    if (this->eventGenerator->eventsAnalis(event))
    {
        this->situation[event->getType()]->data += event->getProgress();
    }

    this->situation[event->getType()]->data -= event->getRegress();
};

void DecisionMakingCenter::addSituation(Situation *situation)
{
    this->situation = (Situation **)realloc(this->situation, sizeof(Situation) * (this->countSituation + 1));
    this->situation[this->countSituation] = situation;
    this->countSituation++;
};