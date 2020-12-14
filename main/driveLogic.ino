//Called when line is lost. Sets custom drive patterns for a certain time.
void noLineHandler() {
  //detachServ();
  //checkFrontSensorsLostLine();
  if(getRightCount() == 8){
    detachServ();
    delay(1000);
    attachServ();
    uTurnHandler();
    incrementRight();
  }
  noLine();
  //Serial.println("NO LINE");
}


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
       // detachServ();
        //delay(250);
        //attachServ();
        Serial.println("Välja fram eller vänster");
        currentMazeSide();
        calibrateDrive();
      }
      
    }
        if  (rightEndSensor()){
      if (!wallInFront()){
        //mazeHandler välj
       // detachServ();
       // delay(250);
       // attachServ();
        Serial.println("Välja fram eller höger");
        currentMazeSide();
        calibrateDrive();
      }
      
    }
    if(leftEndSensor() && rightEndSensor()){
     // detachServ();
     // delay(250);
     // attachServ();
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

void noLine(){
  //if(getRightCount() != 5 || getLeftCount() != 1){
  if(wallRight()&&wallLeft()&&wallInFront()){
    rotateRight();
    delay(120);
    if(wallRight() && wallLeft() && wallInFront()){
    Serial.println("Uturn handler");
    uTurnHandler();
    }
  }
//  }
  
else if((!wallNear() && wallLeft())){
  while((!wallNear() && wallLeft())){
    Wall_p_cont();
    //Serial.println(hc.dist(
    Serial.println("No line turn right");
  }
  rotateRight();
  delay(800);
  forward();
  delay(600);
  while(!getLine()){
    //forward();
    Wall_p_cont();
  }
  //forward();
  //delay(500);
  calibrateDrive();
}

  
}

void uTurnHandler(){
      Serial.println("U TURN");
    // U-Svängen
    detachServ();
    delay(250);
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
