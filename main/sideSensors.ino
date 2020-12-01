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
  
