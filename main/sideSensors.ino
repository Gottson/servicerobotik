void sideSensorSetup() { 
  Serial.begin(9600); 
  }


//return curent distance in serial for sensor 1 to 6
void sideSensorLoop() {
  for (int i = 0; i < 6; i++ ) {
    Serial.println( hc.dist(i) );
    } 
  }
  
