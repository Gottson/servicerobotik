// Servo_luft
#include <Servo.h>
Servo lyft_servo; 
int lyftPin = 3;

// Servo_knip
Servo knip_servo; 
int knipPin = 2; 

// För avståndssensorn (IR-PIN) 
uint8_t distance_limit = 100;
#define IRPin A0; 
uint8_t value_0;
uint8_t i;

// PINS FÖR SWITCH 
int inSwitch = 5; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lyft_servo.attach(lyftPin);
  knip_servo.attach(knipPin); 
  pinMode(inSwitch, 5);  
}

void loop() {
  // put your main code here, to run repeatedly: 
  if (digitalRead(5))
  {
  i = 90; 
  while(i<=180){
  knip_servo.write(i);
  i += 10;
  delay(500);
  }
  lyft_servo.write(40);
  delay(100); 
  lyft_servo.write(90);
  }
   // main-loopen
}
