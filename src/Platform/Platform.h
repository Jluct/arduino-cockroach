#if !defined(Platform)
#include <Arduino.h>

class Platform
{
  protected:
  public:
    virtual void step(bool direction = true);

    /**
     * Только поворот. Направление движения определяются другими методами 
     */
    virtual void rotate(int deg);

    virtual void stop();
};

#endif