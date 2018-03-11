#pragma once

#include "Behavior.h"
#include "../../Platform/Movement/Legs4.h"

Behavior::Behavior(void (*call)(Legs4 *platform))
{
    this->call = call;
};

bool Behavior::getActive()
{
    return this->active;
};

void Behavior::setCall(void (*call)(Legs4 *platform))
{
    this->call = call;
};

void Behavior::callBehavior(Legs4 *platform)
{
    this->call(platform);
};

void Behavior::setNumber(int number)
{
    this->number = number;
};

int Behavior::getNumber()
{
    return this->number;
}