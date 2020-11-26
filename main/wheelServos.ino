void servoSetup(){
  leftServo.attach(10);  // attaches the servos on pins
  rightServo.attach(11);
}

void forward(){
  leftServo.write(83);
  rightServo.write(100);
  delay(15);  
}

void slightRight(){
  leftServo.write(81);
  rightServo.write(100);
   delay(15);  
}

void strongRight(){
 leftServo.write(80);
  rightServo.write(98);

   delay(15);  
}

void outsideRight(){
 leftServo.write(83);
  rightServo.write(90);

   delay(15);  
}

void slightLeft(){
 leftServo.write(83);
  rightServo.write(102);

   delay(15);  
}

void strongLeft(){
 leftServo.write(85);
  rightServo.write(103);

   delay(15);  
}

void outsideLeft(){
 leftServo.write(90);
  rightServo.write(100);

   delay(15);  
}
