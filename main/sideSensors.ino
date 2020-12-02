uint8_t rightVal;
uint8_t leftVal;
void sideSensorSetup() { 

  Serial.begin(9600); 
  }


//return curent distance in serial for sensor 1 to 6
void sideSensorLoop() {
    Serial.print("Left: ");
    Serial.println(hc.dist(0));
    delay(500);
    Serial.print("Right: ");
    Serial.println(hc.dist(1));
    delay(500);
    
  }

void sideSensorCheck(){
  rightVal = hc.dist(1);
  leftVal = hc.dist(0);
  if(rightVal < rightLimit && leftVal>leftLimit){
    //Vi har vägg till höger inte vänster
    //Sväng vänster.
    foward();
    delay(forwardDelay);
    strongLeft();
  }else if(leftVal < leftLimit && rightVal > rightLimit){
    // Vi har vägg till vänster, inte till höger
    // Sväng höger
    forward();
    delay(forwardDelay);
    strongRight();
  }
  else if(leftVal < leftLimit && rightVal < rightLimit){
    // vägg vänster och höger.
    // Titta om vägg är framför ta beslut efter det.
    // if(frontCheck());
    outsideRight();
    delay(turnDelay);
    
  }
}
  
