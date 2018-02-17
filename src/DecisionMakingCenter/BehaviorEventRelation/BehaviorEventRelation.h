#pragma once

#include "../Behavior/Behavior.h"
#include "../EventCenter/Event.h"

struct Relation
{
    Event *event;
    Behavior *behavior;
};