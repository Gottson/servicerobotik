int curr_angle;

void gripServoSetup() {
  lift_servo.attach(liftPin);
  //curr_angle = 80;
  lift_servo.write(restAngle);
  grip_servo.attach(gripPin);   
  delay(15);
  grip_servo.write(gripRestAngle);
}



void collectCylinder() {

    //stay();
    detachServ();
    delay(250);
    grip();
    delay(250);
    lift();
    delay(250);
    unGrip();
    delay(250); 
    unLift();
    delay(250);
    
    grip();
    delay(50);
    lift();
    delay(50);
    unGrip();
    delay(50); 
    unLift();
    delay(50); 
    attachServ();
 
}

void gripperUp(){
  grip();
  lift();
}

 void holdCylinder() {
    stay();
    grip();
    delay(500);
    lift_servo.write(restAngle-15);
}

void grip(){
  for(int i = gripRestAngle; i >= gripAngle; i--){
    grip_servo.write(i);
    delay(10);
  }
    holding = true;
}

void unGrip(){
   for(int i = gripAngle; i <= gripRestAngle; i++){
    grip_servo.write(i);
    delay(10);
  }
  holding = false;
}
  
void lift(){
  gripLifted = true;
    for(int i = restAngle; i >= liftAngle; i--){
      lift_servo.write(i);
      delay(10);
    }
}

void unLift(){
  gripLifted = false;
    for(int i = liftAngle; i <= restAngle; i++){
      lift_servo.write(i);
      delay(10);
    }
  }
