#include <Arduino.h>
#include "./DecisionMakingCenter/DecisionMakingCenter.h"
#include "./DecisionMakingCenter/EventCenter/Event.h"

int isLight()
{
    return random(0, 1023);
}

bool runIsLight(Event *event)
{
    return event->getSensor(0)->getData();
}

void stepRunOfLight()
{
    // както нужно бежать...
    // методы для перемещения в платформе
}

int pins[] = {8, 9, 10, 11};
Legs4 platform(pins);                                   // платформа "4 ноги"
EventGenerator eventGenerator;                          // генератор событий

DecisionMakingCenter dmc(&platform, &eventGenerator);   // центр принятия решений 

Event brightLocation;                                   // событие "локация освещена"
Sensor lightResistor(&isLight);                         // сенсор "фоторезистор"                    
Behavior runOfLight(&stepRunOfLight);                   // поведение "бежать от света"

void setup()
{
    brightLocation.setSensor(&lightResistor);           // добавляем "событию" сенсор
    brightLocation.addLogic(&runIsLight);               // добавляем "событию" обработчик сенсора

    eventGenerator.addAEvent(&brightLocation);          // добавляем событие в генератор событий

    dmc.addBehavior(&runOfLight);                       // добавляем поведение в "центр принятия решений"

}

void loop()
{
    dmc.getEventGenerator()->hasEvent();                // проверяем не наступило ли событие
}