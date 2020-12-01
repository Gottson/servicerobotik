int curr_angle;

void gripServoSetup() {
  Serial.begin(9600);
  lift_servo.attach(liftPin);
  curr_angle = 90;
  lift_servo.write(curr_angle);
  grip_servo.attach(gripPin);   
  pinMode(INPUT, breakSwitch);
}
//Upp i gradantal kniper åt. Stänger på 98 atm
//Upp i gradantal sänker klon.


void gripTop() {
  Serial.println("GRIP TOP"); 
  slowForward();
  delay(500);
  if(!digitalRead(breakSwitch))
  {
    stop();
    _grip();
    _lift();
    _unGrip(); 
    _unLift(); 
  }
}

 void gripHold() {
  Serial.println("GRIP HOLD"); 
  slowForward();
  delay(500);
  if(!digitalRead(breakSwitch))
  {
    stop();
    _grip();
    lift_servo.write(gripAngle+15);
  }
}

void _grip(){
  for(int i = 90; i <= gripAngle; i++){
    grip_servo.write(i);
    delay(10);
  }
}

void _unGrip(){
   for(int i = gripAngle; i >= 90; i--){
    grip_servo.write(i);
    delay(10);
  }
}
  
void _lift(){
    for(int i = 90; i <= liftAngle; i++){
      lift_servo.write(i);
      delay(10);
    }
}

void _unLift(){
    for(int i = liftAngle; i >= 90; i--){
      lift_servo.write(i);
      delay(10);
    }
  }

void liftTest(){
  lift_servo.write(90);
}
