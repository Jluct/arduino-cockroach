#include "Legs4.h"

Legs4::Legs4(int pins[])
{
    this->countDevice = sizeof(pins) / sizeof(int);
    *this->servo = new Servo[this->countDevice];
    for (int i = 0; i < this->countDevice; i++)
    {
        this->servo[i] = &Servo();
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
    int first = this->side ? 120 : 60;
    int second = this->side ? 60 : 120;

    this->servoRotate(first, second);

    this->side = !this->side;
};

void Legs4::stop()
{
    this->servoRotate(90, 90);
};