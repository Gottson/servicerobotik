//Called when line is lost. Sets custom drive patterns for a certain time.
void noLineHandler() {
checkFrontSensorsLostLine();
}

void checkFrontSensorsLostLine(){
  Serial.println("checkFrontSensorsLostLine");
    stay();
    delay(1000);
    while (!wallInFront()){
        Serial.println("Forward in wall left");
        slowForward();
        delay(50);
    }
    checkWallSensorsLostLine();
}


void checkWallSensorsLostLine(){
Serial.println("checkWallSensorsLostLine");
    if(wallLeft() && !wallRight()){
        strongRight();
        delay(1500);
        forwardTillHasLine();
    } else if (!wallLeft() && wallRight()){
        strongLeft();
        delay(1500);
        forwardTillHasLine();
    } else if (wallLeft() && wallRight()){
        // U-Svängen
        stay(); 
        lift(); 
        rotateRight();
        delay(3000);
        while(wallInFront()){
          rotateRight();
          delay(50);
        }
        stay();
        unLift();
    }
}

void forwardTillHasLine(){
  Serial.println("forwardTillHasLine");
    while(!hasLine()){
        slowForward();
        delay(50);
    }
}


void findLine(){
  Serial.println("findLine");
    while(!hasLine()){
      Serial.println("in findLine loop");
        backward();
        delay(500);
        stay();
        delay(500);
    }
    Serial.println("left while findLine");
}



void turnHandler(){
  stay();
  Serial.println("turnHandler");
  delay(1000);
  
  if (wallLeft() && !wallRight()) { 
    Serial.println("Wall left -> strong right");
    strongRight();
    delay(1500);
    if(!hasLine()){
        findLine();
    }

    }
   else if (!wallLeft() && wallRight()) { 
     Serial.println("Wall right -> strong left");
    strongLeft();
    delay(1500);
      if(!hasLine()){
          findLine();
      }
    

    }
    else if (wallLeft() && wallRight()) { 
      Serial.println("Wall left and right. Go forward");
      forward();
      delay(50);
    }
  
  
}

void intersectionHandler(){
  Serial.println("intersectionhadler");
  //if (!wallLeft() && !wallRight()){
    Serial.println("T-section, turning right"); {
    strongRight();
    delay(2500);
  //  }
  }
}
