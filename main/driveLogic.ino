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
    forwardTillHasLine();
  } else if (!wallLeft() && wallRight()) {
    strongLeft();
    delay(1500);
    forwardTillHasLine();
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

void forwardTillHasLine() {
  Serial.println("forwardTillHasLine");
  while (!hasLine()) {
    slowForward();
    delay(50);
  }
}


void findLine() {
  Serial.println("findLine");
  while (!hasLine()) {
    Serial.println("in findLine loop");
    backward();
    delay(500);
    stay();
    delay(500);
  }
  Serial.println("left while findLine");
}



void turnHandler() {
  detachServ();
  Serial.println("turnHandler");
  delay(500);
  attachServ();
  delay(10);
  backward();
  delay(90);
  
  if (wallLeft() && !wallRight()) {
   
    Serial.println("Wall left -> strong right");
    strongRight();
    delay(1500);
   
    
//    
//    if (!hasLine()) {
//      findLine();
//    }



    
  } else if (!wallLeft() && wallRight()) {
    Serial.println("Wall right -> strong left");
    strongLeft();
    delay(1500);

    //if (!hasLine()) {
    ////  findLine();
    //}
  } else if (wallLeft() && wallRight()) {
    Serial.println("Wall left and right. Go forward");
    forward();
    delay(50);
  }


}

void intersectionHandler() {
  detachServ();
  Serial.println("intersectionhadler");
  delay(1000);
  attachServ();
  //if (!wallLeft() && !wallRight()){
  Serial.println("T-section, turning right"); 
   
    //  }
  
   mazeRightSide();
}
