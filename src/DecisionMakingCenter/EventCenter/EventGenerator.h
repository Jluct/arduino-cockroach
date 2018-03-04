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
    struct
    {
        int danger = 0;
        int warning = 0;
        int peace = 0;
        bool testing = true;
    } situation;

    void addActiveEvent(int eventNumber);
    void removeActiveEvent(int eventNUmber);

  public:
    void addAEvent(Event *event);
    void removeEvent(int eventNumber);
    void hasEvent();
};