#include "EventGenerator.h"
#include <Arduino.h>

void EventGenerator::addActiveEvent(int eventNumber)
{
    this->activeIvents = (int *)realloc(this->activeIvents, (this->countActiveEvent + 1) * sizeof(int));
    this->activeIvents[this->countActiveEvent] = eventNumber;
    this->countActiveEvent++;
};

void EventGenerator::removeActiveEvent(int eventNumber)
{
    int *tmp = (int *)realloc(tmp, (this->countActiveEvent - 1) * sizeof(int));
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
    this->activeIvents = new int[this->countActiveEvent];
    memcpy(this->activeIvents, tmp, this->countActiveEvent);
    delete[] tmp;
}

void EventGenerator::addAEvent(Event *event)
{
    // регистрация события
    event->setNumber(this->countEvents);
    if (!this->countEvents)
    {
        this->events[0] = event;
        this->countEvents++;

        return;
    }
    this->countEvents++;
    this->events = (Event **)realloc(this->events, this->countEvents * sizeof(Event));
    this->events[this->countEvents] = event;
};

void EventGenerator::hasEvent()
{
    if (this->events[this->currentIvent]->analizSensors())
    {
        this->addActiveEvent(this->currentIvent);
    } else {
        this->removeActiveEvent(this->currentIvent);
    }

    if (this->currentIvent >= this->countEvents)
    {
        this->currentIvent = 0;
    }
    else
    {
        this->currentIvent++;
    }
};