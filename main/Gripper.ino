int curr_angle;
void gripSetup() {
  Serial.begin(9600);
  lift_servo.attach(liftPin);
  curr_angle = 90;
  lift_servo.write(curr_angle);

  grip_servo.attach(gripPin);   
  pinMode(INPUT, breakSwitch);
}

void gripLoop() {
 delay(500);
  if(!digitalRead(breakSwitch))
  {
    //Do something
  }
//  lift_servo.write(40);
//  delay(100); 
//  lift_servo.write(90);
//  }
//  delay(250);
//  int val1 = digitalRead(5);
//  int val2 = digitalRead(6);
//  Serial.println("start");
//  Serial.println(val1);
//  Serial.println(val2);
//  if(!val1){
//    curr_angle += 2;
//    Serial.println(curr_angle);
//    lift_servo.write(curr_angle);
//    delay(100);
//  }else if(!val2){
//    curr_angle -= 2;
//    Serial.println(curr_angle);
//    lift_servo.write(curr_angle);
//    delay(100);
  }

void _grip(boolean grip){
  if(grip){
  for(int i = 90; i <= gripAngle; i++){
    grip_servo.write(i);
    delay(10);
  }
  lift();
  }else{
   for(int i = gripAngle; i >= 90; i--){
    grip_servo.write(i);
    delay(10);
  } 
  }
}
void _lift(void){
    for(int i = 90; i <= liftAngle; i++){
    lift_servo.write(i);
    delay(10);
  }
}
