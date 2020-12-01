#include <QTRSensors.h>
#include <Servo.h>
#include <HCSR04.h>


// Gripper Initialization
  // Servo_lift
  Servo grip_servo;
  Servo lift_servo;
  #define liftPin 5
  #define gripPin 6
  #define gripAngle 170
  #define liftAngle 170
  
  //IR sensor Initialization
  #define sensorBuff 3
  #define IRPin A1
  #define breakSwitch A0
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

//Side sensors init
HCSR04 hc(16,new int[2]{17,18},2);
//initialisation of class HCSR04 (trig pin , echo pin, number of sensor)


void setup()
{
lineSensorSetup();
wheelServoSetup();
gripServoSetup();
frontSensorSetup();
}

void loop()
{
  //forward();
//sensorCheck();
lineReader();
//gripLoop();
//if(frontCheck()){
//  gripLoop();
//}
//frontCheck();
}
