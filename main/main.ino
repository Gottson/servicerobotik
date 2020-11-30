#include <QTRSensors.h>
#include <Servo.h>


// Gripper Initialization
  // Servo_lift
  Servo grip_servo; 
  Servo lift_servo; 
  #define liftPin 3
  #define gripPin 2
  #define gripAngle 170
  #define liftAngle 170
  
  //IR sensor Initialization
  #define sensorBuff 3
  #define IRPin A1
  #define breakSwitch 3
  int avgDist[sensorBuff];
  uint8_t distance_limit = 100;
  uint8_t front_dist;

  // För avståndssensorn (IR-PIN) 
 

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
//sensorSetup();
//servoSetup();
//gripSetup();
distanceSetup();
}

void loop()
{
//sensorCheck();
//lineReader();
//gripLoop();
//if(frontCheck()){
//  gripLoop();
//}
frontCheck();
}
