#pragma once

#include "Event.h"
#include <Arduino.h>

class EventGenerator
{
private:
  int countActiveEvent = 0;
  Event **activeIvents;

  Event **events;
  int countEvents = 0;

  /**
   * Номер проверяемого события
   */
  int currentIvent = 0;

  void addActiveEvent(Event *event);
  void removeActiveEvent(int eventNumber);
  void controlCurrentIventCounter();

public:
  void addEvent(Event *event);
  void removeEvent(int eventNumber);
  bool eventsAnalis(Event *eventStorage);
  Event **getActiveEvents();
  int getCountActiveEvent();
};