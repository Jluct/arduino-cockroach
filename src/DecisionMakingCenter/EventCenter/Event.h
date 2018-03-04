#pragma once

#include "../../Sensor/Sensor.h"

class Event
{
  private:
    int number; // Текущий номер в генераторе событий
    bool active = false;
    short int type; // Тип события

    Sensor **sensors;
    int countSensors = 0;

    bool (**logic)(Event *event);
    int countLogic = 0;

    int actualSensor = 0;

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

    /**
    * Добавляет сенсор в конец очереди
    */
    void setSensor(Sensor *sensor);
    Sensor *getSensor(int number);
};