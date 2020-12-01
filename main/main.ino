#include <QTRSensors.h>
#include <Servo.h>
#include <HCSR04.h>


// Gripper Initialization
  // Servo_lift
  Servo grip_servo;
  Servo lift_servo;
  #define liftPin 6
  #define gripPin 5
  #define restAngle 135
  #define liftAngle 25
  #define gripAngle 72
  #define gripRestAngle 95
  boolean holding = false;
  
  //Front sensor Initialization
  #define sensorBuff 3
  #define IRPin A1
  int avgDist[sensorBuff];
  uint8_t distance_limit = 100;
  uint8_t front_dist;

  //Brytare
  #define breakSwitch A0

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

//Maze logic
int cylinderCount = 0;

void setup()
{
  sideSensorSetup();
  lineSensorSetup();
  wheelServoSetup();
  gripServoSetup();
  frontSensorSetup();
}

void loop()
{
  //  gripTest();
  //sideSensorLoop();
//gripTest();
//sensorCheck(); 
lineReader();
//frontDistanceCheck();
//
if(frontSwitch()&& !holding){
  Serial.print("<hello");
  gripTop();
//  testGrip();
}
//  
//  if (cylinderCount < 2){
//    gripTop();
//    cylinderCount ++;
//  }
//  else {
//  gripHold();
//  }
// 
//}

}
