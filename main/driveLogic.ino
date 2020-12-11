//Called when line is lost. Sets custom drive patterns for a certain time.
void noLineHandler() {
    Serial.println("Lost line");
    if (wallLeft() && wallRight() && !wallInFront()) {
        Serial.println("Wall left and right, clear forward, go forward");
        forward();
        delay(50);
        //turnIgnore = false;
    }
}

void checkFrontSensorsLostLine(){
    stay();
    delay(1000);
    while (!wallInFront()){
        Serial.println("Forward in wall left");
        forward();
        delay(50);
    }
    checkWallSensorsLostLine();
}

void checkWallSensorsLostLine(){

    if(wallLeft() && !wallRight()){
        rotateRight();
        delay(1500);
        forwardTillHasLine();
    } else if (!wallLeft() && wallRight()){
        rotateLeft();
        delay(1500);
        forwardTillHasLine();
    } else if (!wallLeft() && !wallRight()){
        stay();
        delay(5000);
    }
}

void forwardTillHasLine(){
    while(!hasLine()){
        forward();
        delay(50);
    }
}


void findLine(){
    while(!hasLine()){
        backward();
        delay(50);
    }
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
