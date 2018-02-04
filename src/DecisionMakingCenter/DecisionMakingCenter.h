#if !defined DecisionMakingCenter

#include "../Platform/Movement/Legs4.h"
#include "../Sensor/Sensor.h"
#include "./EventCenter/EventGenerator.h"

class DecisionMakingCenter
{
  private:
    Sensor **sensors;
    int countSensors = 0;
    int currentSensor = 0;
    Legs4 *platform;
    EventGenerator *eventGenerator;

  public:
    DecisionMakingCenter(
        Legs4 *platform,
        EventGenerator *eventGenerator);
    void scanningSpace();
};

#endif