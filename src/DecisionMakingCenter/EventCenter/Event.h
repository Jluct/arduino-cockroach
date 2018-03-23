#pragma once

#include "../../Sensor/Sensor.h"
#include "../Behavior/Behavior.h"
#include "../../Platform/Movement/Legs4.h"

class Event
{
  private:
    int number;          // Текущий номер в генераторе событий
    bool active = false; // Активно ли событие
    short int type = 0;  // Тип события
    int progress = 1;    // Шаг прогресса типа события при вызове события
    int regress = 1;     // Шаг регресса в случае если вобытие не было вызвано

    Sensor **sensors;     // Массив сенсоров
    unsigned int countSensors = 0; // Количество сенсоров

    bool (**logic)(Event *event); // Массив обработки логики срабатывания события
    unsigned int countLogic = 0;  // Количество обработчиков

    unsigned int actualSensor = 0; // текущий сенсор

    Behavior **behavior;   // Массив поведений
    unsigned int countBehavior = 0; // Кол-во добавленных поведений

  public:
    Event();
    void addLogic(bool (*logic)(Event *event));
    bool analizSensors();
    bool hasEvent();

    int getNumber();
    void setNumber(int number);

    bool isActive();
    void setActive(bool active);

    int getType();
    void setType(int type);

    int getCountSensors();
    void callBehavior(unsigned int type, Legs4 *platform);

    void addBehavior(Behavior *behavior);

    /**
    * Добавляет сенсор в конец очереди
    */
    void setSensor(Sensor *sensor);
    bool getSensor(unsigned int number, Sensor *sensor);

    void setProgress(int step);
    void setRegress(int step);

    int getProgress();
    int getRegress();
};