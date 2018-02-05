#if !defined Legs4
#include "../Platform.h"
#include "Servo.h"

class Legs4 : public Platform
{
  private:
    Servo *servo[];
    int countDevice;
    int *pins;

  public:
    Legs4(int pins[]);
};
#endif