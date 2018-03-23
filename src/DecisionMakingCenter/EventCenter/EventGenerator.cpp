#include "EventGenerator.h"
#include <Arduino.h>

void EventGenerator::addActiveEvent(Event *event)
{
    for (int i = 0; i < this->countActiveEvent; i++)
    {
        if (this->activeIvents[i]->getNumber() == event->getNumber())
        {
            return;
        }
    }

    this->activeIvents = (Event **)realloc(this->activeIvents, (this->countActiveEvent + 1) * sizeof(Event *));
    this->activeIvents[this->countActiveEvent] = event;
    this->countActiveEvent++;
};

void EventGenerator::removeActiveEvent(int eventNumber)
{
    if (!this->countActiveEvent || eventNumber < this->countActiveEvent)
    {
        return;
    }

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
    if (this->countActiveEvent)
    {
        memcpy(this->activeIvents, tmp, this->countActiveEvent * sizeof(Event *));
    }
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

/**
 * Управляет внутренним указателем опроса событий
 */
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
 * TODO: Плавающая шкала отключения события 
 * 
 * 
 */
bool EventGenerator::eventsAnalis(Event *eventStorage)
{
    Serial.println(this->currentIvent);
    eventStorage = this->events[this->currentIvent];

    if (eventStorage->analizSensors())
    {
        Serial.println("e-true");
        if (!eventStorage->isActive())
        {
            Serial.println("e-add");
            eventStorage->setActive(true);
            this->addActiveEvent(eventStorage);
        }
        this->controlCurrentIventCounter();

        return true;
    }

    if (eventStorage->isActive())
    {
        Serial.println("e-remove");
        this->removeActiveEvent(this->currentIvent);
        eventStorage->setActive(false);
    }
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