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



void collectCylinder() {

    stop();
    delay(500);
    _grip();
    delay(50);
    _lift();
    delay(50);
    _unGrip();
    delay(50); 
    _unLift();
    delay(50); 
 
}

void gripperUp(){
  _grip();
  _lift();
}

 void holdCylinder() {
    stop();
    _grip();
    delay(500);
    lift_servo.write(restAngle-15);
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
