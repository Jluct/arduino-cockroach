#pragma once

class Behavior
{
  private:
    int number;
    bool active = false;

    void (*call)();

  public:
    Behavior(void (*call)());
    void setNumber(int number);
    int getNumber();
    void setActive(bool active);
    bool getActive();
    void setCall(void (*call)());
    void callBehavior();
};