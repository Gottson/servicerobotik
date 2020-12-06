int last;

void frontSensorSetup(){

  //Front Switch
  pinMode(INPUT, breakSwitch);

  //Distance sensor
  int val = analogRead(IRPin);
  for(int i = 0; i<sensorBuff; i++){
    avgDist[i] = val;
  }
  last = 0;
}

// 85 volt isch 14 cm
// Sets wallInFront to false or true depending on measurements from front sensor
void frontDistanceCheck(){
  front_dist = analogRead(IRPin);
  avgDist[last] = front_dist;
  last += 1;
  if(last==sensorBuff ){
    last = 0;
  }
  int avg = _avgDist(avgDist);
  if(avg > distance_limit){
    wallInFront = true;
  }else{
    wallInFront = false;
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
  if (digitalRead(breakSwitch)){
    return false;
  }
  else{
    return true;
  }
 }
