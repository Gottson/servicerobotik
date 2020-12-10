
void lineSensorSetup(){

  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){7, 3, 4, 2, 13, 12, 9, 8}, SensorCount);


  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

  // Call calibrate() 400 times to make calibration take about 10 seconds.
 
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration


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
  
    posValue = qtr.readLineBlack(sensorValues);
    if(posValue < 2 ){
      Serial.println("Linehandler 1");
      noLineHandler();
    }
     if(posValue < 500 && posValue > 1 ){
      Serial.println("Outside right");
      rotateRight();
    }
     if(posValue < 2000 && posValue > 500){
      Serial.println("Strong right");
      strongRight();
    }
     if(posValue > 2000 && posValue <3000){
      Serial.println("Slight right");
      slightRight();
    }
    if(posValue > 3000 && posValue <3400){
      Serial.println("Forward");
      forward();
    }
    if(posValue > 3400 && posValue <4800){
      Serial.println("Slight left");
      slightLeft();
    }
    if(posValue > 4800 && posValue <6500){
      Serial.println("Strong left");
      strongLeft();
    }
    if(posValue > 6500 && posValue < 6999){
      Serial.println("Outside left");
      rotateLeft();
    }
    if(posValue > 6998 ){
      Serial.println("Linehandler 7000");
      noLineHandler();
    }
    
    delay(50);
}

boolean hasLine(){
  return (7000>qtr.readLineBlack(sensorValues) || qtr.readLineBlack(sensorValues)==0);
}
