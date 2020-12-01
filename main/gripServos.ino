int curr_angle;

void gripServoSetup() {
  Serial.begin(9600);
  lift_servo.attach(liftPin);
  curr_angle = 90;
  lift_servo.write(curr_angle);
  grip_servo.attach(gripPin);   
  pinMode(INPUT, breakSwitch);
}

void gripLoop() {
  slowForward();
  delay(500);
  if(!digitalRead(breakSwitch))
  {
    _grip(true);
  }

  }

void _grip(boolean grip){
  if(grip){
  for(int i = 90; i <= gripAngle; i++){
    grip_servo.write(i);
    delay(10);
  }
  _lift(true);
  }else{
   for(int i = gripAngle; i >= 90; i--){
    grip_servo.write(i);
    delay(10);
  }
  _lift(false); 
  }
}
void _lift(boolean lift){
  if(lift){
    for(int i = 90; i <= liftAngle; i++){
      lift_servo.write(i);
      delay(10);
    }
    _grip(false);
  }else{
    for(int i = liftAngle; i >= 90; i--){
      lift_servo.write(i);
      delay(10);
    }
  }
}
