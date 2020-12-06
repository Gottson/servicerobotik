void sideSensorSetup() { 

  Serial.begin(9600); 
  }


//hc.dist(0) is left distance sensor and 1 is right. Returns distance value in cm.
void leftDistanceCheck() {


   if(hc.dist(0)>side_distance_limit){
    wallLeft = false;
  }

   if(hc.dist(0)<side_distance_limit){
    wallLeft = true;
  }
}

void rightDistanceCheck() {

   if(hc.dist(1)<side_distance_limit){
    wallRight = true;
  }

   if(hc.dist(1)>side_distance_limit){
    wallRight = false;
  }
  
}

  
