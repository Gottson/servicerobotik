#include <QTRSensors.h>
#include <Servo.h>


// Gripper Initialization
  // Servo_lift
  Servo lift_servo; 
  int liftPin = 3;
  // Servo_grip
  Servo grip_servo; 
  int gripPin = 2; 
  // För avståndssensorn (IR-PIN) 
  uint8_t distance_limit = 100;
  #define IRPin A0; 
  uint8_t value_0;
  uint8_t i;
  // PINS FÖR SWITCH 
  int inSwitch = 5; 

// Wheel drive initialization
Servo leftServo;  //when looking in driving direction
Servo rightServo;  

// Line sensor initialization
QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
uint16_t posValue;

void setup()
{
sensorSetup();
servoSetup();
gripSetup();
}

void loop()
{
//sensorCheck();
lineReader();
gripLoop();
}
