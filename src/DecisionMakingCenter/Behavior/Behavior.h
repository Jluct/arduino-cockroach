#pragma once

#include "../../Platform/Movement/Legs4.h"

class Behavior
{
  private:
    int number;
    bool active = false;

    void (*call)(Legs4 *platform);

  public:
    Behavior(void (*call)(Legs4 *platform));
    void setNumber(int number);
    int getNumber();
    void setActive(bool active);
    bool getActive();
    void setCall(void (*call)(Legs4 *platform));
    void callBehavior(Legs4 *platform);
};