void sideSensorSetup() { 
  Serial.begin(9600); 
  }


//return curent distance in serial for sensor 1 to 6
void sideSensorLoop() {
  
    Serial.println(hc.dist(0));
    Serial.println(hc.dist(1));
    
  }
  
