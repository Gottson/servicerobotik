int last;

void frontSensorSetup(){
  Serial.begin(9600);
  int val = analogRead(IRPin);
  for(int i = 0; i<sensorBuff; i++){
    avgDist[i] = val;
  }
  last = 0;
}


boolean frontDistanceCheck(){
  front_dist = analogRead(IRPin);
  avgDist[last] = front_dist;
  last += 1;
  if(last==sensorBuff ){
    last = 0;
  }
  int avg = _avgDist(avgDist);
  //Serial.println("Avg. Dist:" + _avgDist(avgDist));
  delay(250);
  if(avg < distance_limit){
    return true;
    Serial.println("Front distance short"); 
  }else{
    return false;
    Serial.println("Front distance long"); 
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
