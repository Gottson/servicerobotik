int curr_angle;
void gripSetup() {
  Serial.begin(9600);
  lift_servo.attach(liftPin);
  curr_angle = 90;
  lift_servo.write(curr_angle);
  pinMode(INPUT, 5);
  pinMode(INPUT,6);
  //grip_servo.attach(gripPin); 
  //pinMode(inSwitch, 5);  
}

void gripLoop() {
 
//  if (digitalRead(5))
//  {
//  i = 90; 
//  while(i<=180){
//  grip_servo.write(i);
//  i += 10;
//  delay(500);
//  }
//  lift_servo.write(40);
//  delay(100); 
//  lift_servo.write(90);
//  }
  delay(250);
  int val1 = digitalRead(5);
  int val2 = digitalRead(6);
  if(!val1){
    curr_angle += 2;
    Serial.println(curr_angle);
    lift_servo.write(curr_angle);
    delay(100);
  }else if(!val2){
    curr_angle -= 2;
    Serial.println(curr_angle);
    lift_servo.write(curr_angle);
    delay(100);
  }


}
