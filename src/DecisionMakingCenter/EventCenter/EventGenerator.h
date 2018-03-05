#pragma once

#include "Event.h"
#include <Arduino.h>

class EventGenerator
{
  private:
    int countActiveEvent = 0;
    int *activeIvents;

    Event **events;
    int countEvents = 0;

    /**
     * Номер проверяемого события
     */
    int currentIvent = 0;

    void addActiveEvent(int eventNumber);
    void removeActiveEvent(int eventNUmber);

  public:
    void addEvent(Event *event);
    void removeEvent(int eventNumber);
    void eventsAnalis();
};