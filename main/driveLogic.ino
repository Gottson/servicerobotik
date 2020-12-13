//Called when line is lost. Sets custom drive patterns for a certain time.
void noLineHandler() {
  detachServ();
  checkFrontSensorsLostLine();
}

void checkFrontSensorsLostLine() {
  Serial.println("checkFrontSensorsLostLine");
  detachServ();
  delay(1000);
  attachServ();
  while (!wallInFront()) {
    Serial.println("No line and no wall in front, slow forward");
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
    Serial.println("U TURN");
    // U-Svängen
    detachServ();
    delay(1000);
    lift();
    attachServ();
    rotateRight();
    delay(100);
    while(!getLine()){
      rotateRight();
    }
    //while (wallInFront()) {
     // rotateRight();
     // delay(50);
    //}
    detachServ();
    unLift();
    attachServ();
    calibrateDrive();
    stay();
    //unLift();
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
        detachServ();
        delay(2000);
        attachServ();
        Serial.println("Välja fram eller vänster");
        currentMazeSide();
        calibrateDrive();
      }
      
    }
        if  (rightEndSensor()){
      if (!wallInFront()){
        //mazeHandler välj
        detachServ();
        delay(2000);
        attachServ();
        Serial.println("Välja fram eller höger");
        currentMazeSide();
        calibrateDrive();
      }
      
    }
    if(leftEndSensor() && rightEndSensor()){
      detachServ();
      delay(2000);
      attachServ();
      if (wallInFront()){
        //mazeHandler välj väg
        Serial.println("T-section");
        currentMazeSide();
        calibrateDrive();
      }
      else if (!wallInFront()){
        //mazeHandler välj väg
        Serial.println("Cross-section");
        currentMazeSide();
        calibrateDrive();
      }
    }


}
