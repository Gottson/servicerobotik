
void gripSetup() {
  Serial.begin(9600);
  lift_servo.attach(liftPin);
  grip_servo.attach(gripPin); 
  pinMode(inSwitch, 5);  
}

void gripLoop() {
 
  if (digitalRead(5))
  {
  i = 90; 
  while(i<=180){
  grip_servo.write(i);
  i += 10;
  delay(500);
  }
  lift_servo.write(40);
  delay(100); 
  lift_servo.write(90);
  }
}
