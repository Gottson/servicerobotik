int last;

void frontSensorSetup(){

  //Switch
  pinMode(INPUT, breakSwitch);

  //Distance sensor
  int val = analogRead(IRPin);
  for(int i = 0; i<sensorBuff; i++){
    avgDist[i] = val;
  }
  last = 0;
}


void frontDistanceCheck(){
  front_dist = analogRead(IRPin);
  avgDist[last] = front_dist;
  last += 1;
  if(last==sensorBuff ){
    last = 0;
  }
  int avg = _avgDist(avgDist);
  //Serial.println("Avg. Dist:" + _avgDist(avgDist));
  //delay(50);
  if(avg > distance_limit){
   // Serial.println("WALL"); 
    //Serial.print("Front: ");
    //Serial.println(avg); 
    wallInFront = true;

  }else{
   // Serial.println("CLEAR"); 
    //Serial.print("Front: ");
    //Serial.println(avg); 
    wallInFront = false;
  
  }
  // 85 volt isch 14 cm
  
}

int _avgDist(int dist[]){
  int avg = 0;
  for(int i = 0; i<sensorBuff;i++){
    avg += avgDist[i];
  }
  return avg/sensorBuff; 
  
}

boolean frontSwitch(){
  if (digitalRead(breakSwitch)){
    return false;
  }
  else{
    return true;
  }
  
 }
