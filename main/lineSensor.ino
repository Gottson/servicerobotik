float Kp = 0.013; //set up the constants value
float Ki = 0;
float Kd = 0.013;
int P;
int I;
int D;
//Set basevalues for straightline (a = left, b = right);
int basespeeda = 120;
int basespeedb = 120;

//Increasing the maxspeed can damage the motors - at a value of 255 the 6V motors will receive 7,4 V 
const uint8_t maxspeeda = 180;
const uint8_t maxspeedb = 180;

int lastError = 0;
boolean onoff = false;

void lineSensorSetup(){

  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){7, 3, 4, 2, 13, 12, 9, 8}, SensorCount);


  delay(500);
  //pinMode(LED_BUILTIN, OUTPUT);
  //digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

  // Call calibrate() 400 times to make calibration take about 10 seconds.
 
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  //digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration


}


void sensorCheck(){
 
  posValue = qtr.readLineBlack(sensorValues);
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(posValue);

  delay(250);
}

//Get the linecommanders calculated position and sets direction + prints recommendation
void lineDriveCommander() {

  if(!onoff){
    delay(1000);
    onoff = !onoff;
  }
  if(onoff){
    PID_control();
  }
}
void PID_control() {
  uint16_t position = qtr.readLineBlack(sensorValues);
  int error = 3000 - position;

  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  int motorspeed = P*Kp + I*Ki + D*Kd;
  
  int motorspeeda = basespeeda + motorspeed;
  int motorspeedb = basespeedb - motorspeed;
  
  
  if (motorspeeda > maxspeeda) {
    motorspeeda = maxspeeda;
  }
  if (motorspeedb > maxspeedb) {
    motorspeedb = maxspeedb;
  }
  if (motorspeeda < 0) {
    motorspeeda = 0;
  }
  if (motorspeedb < 0) {
    motorspeedb = 0;
  } 
   //motorspeedb = 180 - motorspeedb;
   motorspeeda = 180 - motorspeeda;
   
  _updatePWM(motorspeeda, motorspeedb);
  //Serial.print(motorspeeda);Serial.print(" ");Serial.println(motorspeedb);
}

void _updatePWM(int motorspeeda, int motorspeedb){
    if(motorspeedb<0){
      rightServo.write(0);
    }else if(motorspeedb>180){
      rightServo.write(180);
    }else{
      rightServo.write(motorspeedb);
    }
    if(motorspeeda<0){
      leftServo.write(0);
    }else if(motorspeeda > 180){
      leftServo.write(180);
    }else{
      leftServo.write(motorspeeda);
    }
//    Serial.println("------------");
//    Serial.println("Left:");
//    Serial.println(motorspeeda);
//    Serial.println("Right");
//    Serial.println(motorspeedb);
//    Serial.println("------------");
}

void hasLine(){
  posValue = qtr.readLineBlack(sensorValues);
  //Serial.println(qtr.readLineBlack(sensorValues));
  if (0==posValue || posValue == 7000){
    noLineHandler();
  }
}

boolean leftEndSensor(){
  qtr.readLineBlack(sensorValues);
  //Serial.println(sensorValues[7]);
  if (sensorValues[7]>500){
    return true;
  }
  else{
    return false;
  }
}
boolean rightEndSensor(){
  qtr.readLineBlack(sensorValues);
  //Serial.println(sensorValues[0]);
  if (sensorValues[0]>500){
    return true;
  }
  else{
    return false;
  }
}
