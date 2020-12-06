#include <QTRSensors.h>
#include <Servo.h>
#include <HCSR04.h>


// Gripper Initialization

Servo grip_servo;
Servo lift_servo;
#define liftPin 6
#define gripPin 5
#define restAngle 135 //Upp i gradantal sänker klon.
#define liftAngle 30
#define gripAngle 72 //Ned i gradantal kniper åt.
#define gripRestAngle 95
boolean holding = false;
  
//Front sensor Initialization
#define sensorBuff 3
#define IRPin A1
int avgDist[sensorBuff];
uint8_t distance_limit = 50;
uint8_t front_dist;
boolean wallInFront = false;

//Brytare
#define breakSwitch A0

// Wheel drive initialization
Servo leftServo;   //when looking in driving direction
Servo rightServo;  //when looking in driving direction

// Line sensor initialization
QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
uint16_t posValue;
//boolean hasLine = true;

//Side sensors init
HCSR04 hc(16,new int[2]{17,18},2);
//initialisation of class HCSR04 (trig pin , echo pin, number of sensor)
uint8_t side_distance_limit = 14;
boolean wallLeft = false;
boolean wallRight = false;

//Maze logic
int cylinderCount = 0;

void setup()
{
  sideSensorSetup();
  lineSensorSetup();
  wheelServoSetup();
  gripServoSetup();
  frontSensorSetup();
  
  gripperUp();
}

void loop()
{



lineDriveCommander();


}
