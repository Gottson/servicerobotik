//Called when line is lost. Sets custom drive patterns for a certain time.
void noLineHandler() {
  checkFrontSensorsLostLine();
}

void checkFrontSensorsLostLine() {
  Serial.println("checkFrontSensorsLostLine");
  detachServ();
  delay(1000);
  attachServ();
  while (!wallInFront()) {
    Serial.println("Forward in wall left");
    slowForward();
    delay(50);
  }
  checkWallSensorsLostLine();
}


void checkWallSensorsLostLine() {
  Serial.println("checkWallSensorsLostLine");
  detachServ();
  delay(1000);
  attachServ();
  if (wallLeft() && !wallRight()) {
    strongRight();
    delay(1500);
    forward();
    delay(1500);
    //forwardTillHasLine();
  } else if (!wallLeft() && wallRight()) {
    strongLeft();
    delay(1500);
    //forwardTillHasLine();
    forward();
    delay(1500);
  } else if (wallLeft() && wallRight()) {
    // U-Svängen
    stay();
    lift();
    rotateRight();
    delay(3000);
    while (wallInFront()) {
      rotateRight();
      delay(50);
    }
    stay();
    unLift();
  }
}

//void forwardTillHasLine() {
//  Serial.println("forwardTillHasLine");
//  while (!hasLine()) {
//    slowForward();
//    delay(50);
//  }
//}


//void findLine() {
//  Serial.println("findLine");
//  while (!hasLine()) {
//    Serial.println("in findLine loop");
//    backward();
//    delay(500);
//    stay();
//    delay(500);
//  }
//  Serial.println("left while findLine");
//}



int choiceCount(){
  int i = 0;
  if (!wallInFront()){
    i ++;
  }
  if (!wallLeft()){
    i++;
  }
  if (!wallRight()){
    i++;
  }
  return i;
}


//controls cases where more than one path is awaiable.
void choiceHandler(){
    
    posValue = qtr.readLineBlack(sensorValues);
    if  (leftEndSensor()){
      if (!wallInFront()){
        //mazeHandler välj väg
        Serial.println("Välja fram eller vänster");
        currentMazeSide();
      }
      
    }
        if  (rightEndSensor()){
      if (!wallInFront()){
        //mazeHandler välj
        Serial.println("Välja fram eller höger");
        currentMazeSide();
      }
      
    }
    if(leftEndSensor() && rightEndSensor()){
      if (wallInFront()){
        //mazeHandler välj väg
        Serial.println("T-section");
        currentMazeSide();
      }
      else if (!wallInFront()){
        //mazeHandler välj väg
        Serial.println("Cross-section");
        currentMazeSide();
      }
    }

}
