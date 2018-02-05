#if !defined DecisionMakingCenter

#include "../Platform/Movement/Legs4.h"
#include "../Sensor/Sensor.h"
#include "./EventCenter/EventGenerator.h"

class DecisionMakingCenter
{
  private:
    Sensor **sensors;
    int countSensors = 0;           // кол-во сенсоров
    int currentSensor = 0;          // номер текущего опрашиваемого датчика
    Legs4 *platform;                // Палтформа передвижения
    EventGenerator *eventGenerator; // Генератор событий

  public:
    DecisionMakingCenter(
        Legs4 *platform,
        EventGenerator *eventGenerator);

    /**
     * Вызывает датчики по очерёдности. 
     * Внутренний указатель ссылается на дачик, который необходимо опросить на данный момент
     */
    void scanningSpace();
    
    /**
     * Добавляет сенсор в конец очереди
     */
    void setSensor(Sensor *sensor);
};

#endif