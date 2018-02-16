#include "Behavior.h"

bool Behavior::getActive()
{
    return this->active;
};

void Behavior::setCall(void (*call)())
{
    this->call = call;
};

void Behavior::callBehavior()
{
    this->call();
};

void Behavior::setNumber(int number)
{
    this->number = number;
};

int Behavior::getNumber()
{
    return this->number;
}
