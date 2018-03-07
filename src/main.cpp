#include <Arduino.h>
#include "./DecisionMakingCenter/DecisionMakingCenter.h"
#include "./DecisionMakingCenter/EventCenter/Event.h"

/**
 * функция-заглушка
 * получение показаний с фоторезистора
 */
int isLight()
{
    return random(0, 1023);
}

/**
 * интерпретация данных с фоторезистора 
 */
bool tooBright(Event *event)
{
    return event->getSensor(0)->getData() >= 500;
}

/**
 * Логика поведения в случае генерирования события
 * TODO: Выбор интерпретации в зависимости от "очков ситуации"
 * Это позволит выбирать наиболее подходящее поведении в данный момент
 */
void stepRunOfLight()
{
    // както нужно бежать...
    // методы для перемещения в платформе
}

int pins[] = {8, 9, 10, 11};
Legs4 platform(pins);          // платформа "4 ноги"
EventGenerator eventGenerator; // генератор событий

DecisionMakingCenter dmc(&platform, &eventGenerator); // центр принятия решений

Event brightLocation;                 // событие "локация освещена"
Sensor lightResistor(&isLight);       // сенсор "фоторезистор"
Behavior runOfLight(&stepRunOfLight); // поведение "бежать от света"

void setup()
{
    brightLocation.setType(1);                // Указываем тип события
    brightLocation.setProgress(10);           // Устанавливаем шаг прогресса ситуации
    brightLocation.setSensor(&lightResistor); // добавляем "событию" сенсор
    brightLocation.addLogic(&tooBright);      // добавляем "событию" обработчик сенсора
    brightLocation.addBehavior(&runOfLight);  // добавляем поведение в событие

    eventGenerator.addEvent(&brightLocation); // добавляем событие в генератор событий
}

void loop()
{
    // dmc.getEventGenerator()->eventsAnalis(); // проверяем не наступило ли событие
}