int curr_angle;

void gripServoSetup() {
  Serial.begin(9600);
  lift_servo.attach(liftPin);
  //curr_angle = 80;
  lift_servo.write(restAngle);
  grip_servo.attach(gripPin);   
  delay(15);
  grip_servo.write(gripRestAngle);
}
//Upp i gradantal kniper åt. Stänger på 98 atm
//Upp i gradantal sänker klon.


void gripTop() {
  Serial.println("GRIP TOP"); 
  //slowForward();
  stop();
  delay(900);
  
    stop();
    _grip();
    _lift();
    _unGrip(); 
    _unLift(); 
 
}

void gripperDriveMode(){
  _grip();
  _lift();
}

 void gripHold() {
  Serial.println("GRIP HOLD"); 
//  slowForward();
//  delay(500);
//  if(frontSwitch())
//  {
    stop();
    _grip();
    delay(500);
    lift_servo.write(restAngle-15);
//  }
}

void _grip(){
  for(int i = gripRestAngle; i >= gripAngle; i--){
    grip_servo.write(i);
    delay(10);
  }
    holding = true;
}

void _unGrip(){
   for(int i = gripAngle; i <= gripRestAngle; i++){
    grip_servo.write(i);
    delay(10);
  }
  holding = false;
}
  
void _lift(){
    for(int i = restAngle; i >= liftAngle; i--){
      lift_servo.write(i);
      delay(10);
    }
}

void _unLift(){
    for(int i = liftAngle; i <= restAngle; i++){
      lift_servo.write(i);
      delay(10);
    }
  }

void gripTest(){
  grip_servo.write(80);
  delay(50);
  lift_servo.write(restAngle);
  
  
}
