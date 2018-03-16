#include "Legs4.h"
#include <Arduino.h>
#include "Servo.h"

void Legs4::init(int *pins)
{
    this->countDevice = 2;
    this->servo = (Servo **)realloc(this->servo, sizeof(Servo *) * this->countDevice);
    for (int i = 0; i < this->countDevice; i++)
    {
        this->servo[i] = new Servo;
        this->servo[i]->attach(pins[i]);
        this->servo[i]->write(90);
    }
};

void Legs4::servoRotate(int first, int second)
{
    this->servo[0]->write(first);
    this->servo[1]->write(second);
}

/**
 * Шаг - поворот серво на +/-30 градусов
 * серво[0] - переднее серво
 * серво[1] - заднее серво
 */
void Legs4::step()
{
    int first = this->side ? 180 : 0;
    int second = !this->side ? 180 : 0;

    this->servoRotate(first, second);
    this->side = !this->side;
};

void Legs4::stop()
{
    this->servoRotate(90, 90);
};