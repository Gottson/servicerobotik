
void gripSetup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lyft_servo.attach(lyftPin);
  knip_servo.attach(knipPin); 
  pinMode(inSwitch, 5);  
}

void gripLoop() {
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
