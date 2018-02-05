#include "Legs4.h"

Legs4::Legs4(int pins[])
{
    this->countDevice = sizeof(pins) / sizeof(int);
    *this->servo = new Servo[this->countDevice];
    for (int i = 0; i < this->countDevice; i++)
    {
        this->servo[i] = &Servo();
        this->servo[i]->attach(pins[i]);
    }
}