void servoSetup(){
  leftServo.attach(11);  // attaches the servos on pins
  rightServo.attach(10);
}

void forward(){
  leftServo.write(73);
  rightServo.write(110);
  delay(15);  
}

void slightRight(){
  leftServo.write(70);
  rightServo.write(105);
   delay(15);  
}

void strongRight(){
 leftServo.write(60);
  rightServo.write(98);

   delay(15);  
}

void outsideRight(){
 leftServo.write(70);
  rightServo.write(90);

   delay(15);  
}

void slightLeft(){
 leftServo.write(73);
  rightServo.write(115);

   delay(15);  
}

void strongLeft(){
 leftServo.write(85);
  rightServo.write(115);

   delay(15);  
}

void outsideLeft(){
 leftServo.write(90);
  rightServo.write(110);

   delay(15);  
}
