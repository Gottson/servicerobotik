void wheelServoSetup(){
  leftServo.attach(10);  // attaches the servos on pins
  rightServo.attach(11);
}

void forward(){
  leftServo.write(75);
  rightServo.write(105);
  delay(15);  
}
void backward(){
    leftServo.write(100);
    rightServo.write(80);
    delay(15);
}

void slowForward(){
  leftServo.write(83);
  rightServo.write(95);
  delay(15);
}

void stay(){
  leftServo.write(90);
  rightServo.write(90);
}

void slightRight(){
  leftServo.write(80);
  rightServo.write(97);
   delay(15);  
}

void strongRight(){
 leftServo.write(80);
  rightServo.write(90);

   delay(15);  
}

void rotateRight(){
 leftServo.write(75);
  rightServo.write(75);

   delay(15);  
}

void slightLeft(){
 leftServo.write(83);
  rightServo.write(100);

   delay(15);  
}

void strongLeft(){
 leftServo.write(90);
  rightServo.write(100);

   delay(15);  
}

void rotateLeft(){
 leftServo.write(95);
  rightServo.write(95);

   delay(15);  
}

void uTurn(){
 leftServo.write(95);
  rightServo.write(95);
  }


void detachServ(){
  leftServo.detach(); // attaches the servos on pins
  rightServo.detach();
  }

void attachServ(){
  leftServo.attach(10); // attaches the servos on pins
  rightServo.attach(11);
  }
