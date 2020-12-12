void sideSensorSetup() { 

  Serial.begin(9600); 
  }


//hc.dist(0) is left distance sensor and 1 is right. Returns distance value in cm.
boolean wallLeft() {


   if(hc.dist(0)>side_distance_limit){
    return false;
  }

   if(hc.dist(0)<side_distance_limit){
    return true;
  }
}

boolean wallRight() {

   if(hc.dist(1)<side_distance_limit){
    return true;
  }

   if(hc.dist(1)>side_distance_limit){
    return false;
  }
  
}

  
