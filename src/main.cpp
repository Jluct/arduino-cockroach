#include <Arduino.h>
#include "./DecisionMakingCenter/DecisionMakingCenter.h"
// #include "./Platform/Movement/Legs4.h"

int pins[] = {8, 9, 10, 11};
Legs4 platform(pins);
EventGenerator eventGenerator;

DecisionMakingCenter dmc(&platform, &eventGenerator);

void setup()
{
    // put your setup code here, to run once:
}

void loop()
{
    // put your main code here, to run repeatedly:
}