#pragma once

#include <Arduino.h>
#include "Servo.h"

/**
 * Платформа на 2 серво (4 ноги)
 * Установка серво на 90 градусов и ноги препендикулярно корпусу 
 */
class Legs4
{
  private:
    Servo **servo;
    int countDevice;
    int *pins;
    /**
     * Сторона текущего шага
     */
    bool side = true;

    void servoRotate(int first, int second);

  public:
    void init(int *pins);

    void step();

    /**
     * Только поворот. Направление движения определяются другими методами 
     */
    void rotate(int deg);

    void stop();
};