#include <Arduino.h>
#include "./DecisionMakingCenter/DecisionMakingCenter.h"
// #include "./Platform/Movement/Legs4.h"

int isLight()
{
    return random(0, 1023);
};

bool runIsLight(int light)
{
    return light > 500 ? true : false;
};

int pins[] = {8, 9, 10, 11};
Legs4 platform(pins);
EventGenerator eventGenerator;

Sensor lightResistor(&isLight);

DecisionMakingCenter dmc(&platform, &eventGenerator);

// dmc.setSensor(&lightResistor);

void setup()
{
    // dmc.setSensor(&lightResistor);
    // put your setup code here, to run once:
}

void loop()
{
    // put your main code here, to run repeatedly:
}