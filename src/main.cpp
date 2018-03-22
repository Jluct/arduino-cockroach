/**
 * В ресет уходим, ищем причину,и цикла проверки по прежнему нет
 * Проблема не в отсутствии задержки?
 * 
 * При передаче данных на большой скорости в сериал они доходят
 * При низкой скорости - только 2 байта
 * При низкой скорости и задержке - доходят!
 */

#include <Arduino.h>
#include "./DecisionMakingCenter/DecisionMakingCenter.h"
#include "./DecisionMakingCenter/EventCenter/Event.h"
#include "Servo.h"

/**
 * функция-заглушка
 * получение показаний с фоторезистора
 */
int isLight()
{
    // Serial.println(110, DEC);
    // return analogRead(A0);
    // int data = random(0, 1023);
    int data = 0;
    Serial.println("isLight");

    return data;
}

/**
 * Обработка данных с сенсоров
 * интерпретация данных с фоторезистора 
 */
bool tooBright(Event *event)
{
    Sensor *sensor1;
    // Serial.println("tooBright");
    // проверяем есть ли такой сенсор
    if (event->getSensor(0, sensor1))
    {
        int data = sensor1->request();
        Serial.println((int)data, DEC);
        return data >= 100;
    } else {
        Serial.println("no");
    }

    return false;
}

/**
 * Логика поведения в случае генерирования события
 * Это позволит выбирать наиболее подходящее поведении в данный момент
 */
void stepRunOfLight(Legs4 *platform)
{
    // Serial.println(112, DEC);
    platform->step();
}

void defaultAction(Legs4 *platform)
{
    // Serial.println(113, DEC);
    platform->stop();
}

DecisionMakingCenter dmc; // центр принятия решений

void setup()
{
    /**
     * Debug 
     */
    Serial.begin(115200);
    pinMode(13, OUTPUT);

    /**
     * Дебаг показывающий, что скетч инициализируется
     */
    Serial.println("setup");
    digitalWrite(13, HIGH);
    delay(1000);

    int pins[] = {9, 10};
    Legs4 platform; // платформа "4 ноги"

    EventGenerator eventGenerator; // генератор событий

    Event brightLocation;           // событие "локация освещена"
    Sensor lightResistor(&isLight); // сенсор "фоторезистор"

    Behavior defaultBehavior(&defaultAction); // поведение по умолчанию
    Behavior runOfLight(&stepRunOfLight);     // поведение "бежать от света"

    //TODO: Вынести в фабрику
    struct Situation defaultSituation = {"default", 0}; // ситуация по умолчанию
    struct Situation dangerSituation = {"danger", 0};   // ситуация "опасность"

    platform.init(pins); // Передаём массив с пинами для инициализации серво

    dmc.addSituation(&defaultSituation); // Добавляем дефолтную ситуацию
    dmc.addSituation(&dangerSituation);  // Добавляем ситуацию "опасность"

    brightLocation.setType(0);      // Указываем тип события
    brightLocation.setProgress(10); // Устанавливаем шаг прогресса ситуации

    /** 
     * ТОЧКА ЗАВИСАНИЯ
     * Не хватает памяти?
     * Поменял местами с setSensor 
     * всё заработало
    */
    brightLocation.addBehavior(&defaultBehavior); // добавляем дефолтное поведение в событие
    brightLocation.addBehavior(&runOfLight);      // добавляем поведение в событие в случае если локация освещена

    brightLocation.setSensor(&lightResistor); // добавляем "событию" сенсор
    brightLocation.addLogic(&tooBright);      // добавляем "событию" обработчик сенсора

    /** 
     * ТОЧКА ЗАВИСАНИЯ
     * LOOP выполняется только один раз
     * приходит мусор
     * Закоментил  dmc.init и всё заработало
    */
    eventGenerator.addEvent(&brightLocation); // добавляем событие в генератор событий

    dmc.init(&platform, &eventGenerator); // центр принятия решений

    digitalWrite(13, LOW);
}

void loop()
{
    Serial.println("LOOP");
    // digitalWrite(13, HIGH);
    delay(1000);
    // digitalWrite(13, LOW);
    // delay(1000);
    // delay(300);
    dmc.testSituation(); // проверяем не наступило ли событие
    // delay(300);
    dmc.callBehavior();  // вызываем обработчик события по ситуации
}