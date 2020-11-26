#include <QTRSensors.h>
#include <Servo.h>

Servo leftServo;  //when looking in driving direction
Servo rightServo;  

QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
uint16_t posValue;


void setup()
{
sensorSetup();
servoSetup();
}


void loop()
{
//sensorCheck();
turnCommander();
}
