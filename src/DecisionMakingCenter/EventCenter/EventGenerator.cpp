#include "EventGenerator.h"
#include <Arduino.h>

void EventGenerator::addActiveEvent(Event *event)
{
    this->activeIvents = (Event **)realloc(this->activeIvents, (this->countActiveEvent + 1) * sizeof(Event *));
    this->activeIvents[this->countActiveEvent] = event;
    this->countActiveEvent++;
};

void EventGenerator::removeActiveEvent(int eventNumber)
{
    Event **tmp = (Event **)realloc(tmp, (this->countActiveEvent - 1) * sizeof(Event *));
    for (int i = 0; i < this->countActiveEvent; i++)
    {
        if (i == eventNumber)
        {
            continue;
        }

        tmp[i] = this->activeIvents[i];
    }

    this->countActiveEvent--;
    delete[] this->activeIvents;
    this->activeIvents = (Event **)realloc(this->activeIvents, this->countActiveEvent * sizeof(Event *));
    memcpy(this->activeIvents, tmp, this->countActiveEvent * sizeof(Event *));
    delete[] tmp;
}

void EventGenerator::addEvent(Event *event)
{
    // регистрация события
    event->setNumber(this->countEvents);

    this->events = (Event **)realloc(this->events, (this->countEvents + 1) * sizeof(Event *));
    this->events[this->countEvents] = event;
    this->countEvents++;
};

void EventGenerator::controlCurrentIventCounter()
{
    if (this->currentIvent >= this->countEvents)
    {
        this->currentIvent = 0;
    }
    else
    {
        this->currentIvent++;
    }
}

/**
 * Проверка на существования события
 * По очереди вызываются события и связанные с ними датчики
 * в случае если метод возвращает true считается что возникает событие
 * Событие добавляется в список активных событий
 * 
 * Event *eventStorage - ссылка на область памяти куда будет помещён объект события
 * 
 */
bool EventGenerator::eventsAnalis(Event *eventStorage)
{
    // Serial.println("eventsAnalis");
    eventStorage = this->events[this->currentIvent];

    if (this->events[this->currentIvent]->analizSensors())
    {
        Serial.println("e true");
        this->events[this->currentIvent]->setActive(true);
        this->addActiveEvent(this->events[this->currentIvent]);
        this->controlCurrentIventCounter();

        return true;
    }

    this->events[this->currentIvent]->setActive(false);
    this->removeActiveEvent(this->currentIvent);
    this->controlCurrentIventCounter();

    return false;
};

Event **EventGenerator::getActiveEvents()
{
    return this->activeIvents;
};

int EventGenerator::getCountActiveEvent()
{
    return this->countActiveEvent;
};