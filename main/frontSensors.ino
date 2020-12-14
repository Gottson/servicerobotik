int last;

void frontSensorSetup(){

  //Front Switch
  pinMode(INPUT, breakSwitch);

  //Distance sensor
//  int val = analogRead(IRPin);
//  for(int i = 0; i<sensorBuff; i++){
//    avgDist[i] = val;
//  }
//  last = 0;
}

// 85 volt isch 14 cm
// Sets wallInFront to false or true depending on measurements from front sensor
boolean wallInFront(){
  //Serial.println("We are in wallInFront");
  for(int i=0; i<sensorBuff; i++){
    avgDist[i] = analogRead(IRPin);
    //Serial.println(analogRead(IRPin));
  }
  //Serial.println(avgDist);
  int avg = _avgDist(avgDist);
  //Serial.println(avg);
  if(avg > distance_limit){
    return true;
  }else{
    return false;
  }
}

boolean wallNear(){
  //Serial.println("We are in wallInFront");
  for(int i=0; i<sensorBuff; i++){
    avgDist[i] = analogRead(IRPin);
    //Serial.println(analogRead(IRPin));
  }
  //Serial.println(avgDist);
  int avg = _avgDist(avgDist);
  //Serial.println(avg);
  if(avg > 95){
    return true;
  }else{
    return false;
  }
}

int _avgDist(int dist[]){
  int avg = 0;
  for(int i = 0; i<sensorBuff;i++){
    avg += avgDist[i];
  }
  return avg/sensorBuff; 
}


//Returns value of front switch
boolean frontSwitch(){
  return !digitalRead(breakSwitch);
 }
