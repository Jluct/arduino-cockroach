#if !defined Legs4
#include "../Platform.h"

class Legs4 : public Platform
{
  public:
    int *pins;
    Legs4(int pins[]);
};
#endif