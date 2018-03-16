#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#include "DecisionMakingCenter.h"
#include "DecisionMakingCenter/Situation/Situation.h"
#include "../Platform/Movement/Legs4.h"

int DecisionMakingCenter::getActualSituation()
{
    int rezult = 0;
    unsigned long int max = 0;

    for (int i = 0; i < this->countSituation; i++)
    {
        if (this->situation[i]->data >= max)
        {
            max = this->situation[i]->data;
            rezult = i;
        }
    }

    return rezult;
};

EventGenerator *DecisionMakingCenter::getEventGenerator()
{
    return this->eventGenerator;
};

void DecisionMakingCenter::init(Legs4 *platform, EventGenerator *eventGenerator)
{
    this->platform = platform;
    this->eventGenerator = eventGenerator;
};

void DecisionMakingCenter::callBehavior()
{
    for (int i = 0; this->eventGenerator->getCountActiveEvent(); i++)
    {
        Event *event = this->eventGenerator->getActiveEvents()[i];
        event->callBehavior(this->getActualSituation(), this->platform);
    }
};

/**
 * Проверка на вызов события
 * Если событие было вызвано то управление передаётся дальше
 * Если нет - уменьшаем счётчик текущей ситуации
 * 
 * TODO: Пределы ситуциации вынести в свойства со значением по умолчанию
 * 
 */
void DecisionMakingCenter::testSituation()
{
    Event *event;
    if (this->eventGenerator->eventsAnalis(event))
    {
        this->situation[event->getType()]->data += this->situation[event->getType()]->data < 500 ? event->getProgress() : 0;
    }

    this->situation[event->getType()]->data -= this->situation[event->getType()]->data > 0 ? event->getRegress() : 0;
};

void DecisionMakingCenter::addSituation(Situation *situation)
{
    this->situation = (Situation **)realloc(this->situation, sizeof(Situation*) * (this->countSituation + 1));
    this->situation[this->countSituation] = situation;
    this->countSituation++;
};