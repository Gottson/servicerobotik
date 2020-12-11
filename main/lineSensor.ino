
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
      if(!turnIgnore){
      turnIgnore = true;
      noLineHandler();
      }
      
    }
     if(posValue < 1000 && posValue > 1 ){
      rotateRight();
    }
     if(posValue < 2000 && posValue > 1000){
      if(!turnIgnore){
      turnHandler();
      }
      turnIgnore = true;
      strongRight();
    }
     if(posValue > 2000 && posValue <3000){
      slightRight();
    }
    if(posValue > 3000 && posValue <3400){
      forward();
      turnIgnore = false;
    }
    if(posValue > 3400 && posValue <4500){
      if (posValue == 3500){
          delay(15);
        if (qtr.readLineBlack(sensorValues) == 3500){
        if (!turnIgnore){
          intersectionHandler();
          turnIgnore=true;

        }
        }        
      }
      slightLeft();
    }
    if(posValue > 4500 && posValue <6000){
      if (!turnIgnore){
      turnHandler();
      }
      turnIgnore = true;
      strongLeft();
    }
    if(posValue > 6000 && posValue < 7000){
      rotateLeft();
    }
    if(posValue > 6999 ){
      if(!turnIgnore){
         turnIgnore = true;
         noLineHandler();
      }

    }
    
    delay(50);
}

boolean hasLine(){
  return (7000==qtr.readLineBlack(sensorValues) || qtr.readLineBlack(sensorValues)==0);
}
