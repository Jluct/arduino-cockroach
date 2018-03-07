#pragma once

#include "../../Sensor/Sensor.h"
#include "../Behavior/Behavior.h"

class Event
{
  private:
    int number;           // Текущий номер в генераторе событий
    bool active = false;  // Активно ли событие
    short int type;       // Тип события
    int progress = 1; // Шаг прогресса типа события при вызове события
    int regress = 1;  // Шаг регресса в случае если вобытие не было вызвано

    Sensor **sensors;     // Массив сенсоров
    int countSensors = 0; // Количество сенсоров

    bool (**logic)(Event *event); // Массив обработки логики срабатывания события
    int countLogic = 0;           // Количество обработчиков

    int actualSensor = 0;

    Behavior **behavior;   // Массив поведений
    int countBehavior = 0; // Кол-во добавленных поведений

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
    void callBehavior(int type);

    void addBehavior(Behavior *behavior);

    /**
    * Добавляет сенсор в конец очереди
    */
    void setSensor(Sensor *sensor);
    Sensor *getSensor(int number);

    void setProgress(int step);
    void setRegress(int step);

    int getProgress();
    int getRegress();
};