// This example is designed for use with eight RC QTR sensors. These
// reflectance sensors should be connected to digital pins 3 to 10. The
// sensors' emitter control pin (CTRL or LEDON) can optionally be connected to
// digital pin 2, or you can leave it disconnected and remove the call to
// setEmitterPin().
//
// The setup phase of this example calibrates the sensors for ten seconds and
// turns on the Arduino's LED (usually on pin 13) while calibration is going
// on. During this phase, you should expose each reflectance sensor to the
// lightest and darkest readings they will encounter. For example, if you are
// making a line follower, you should slide the sensors across the line during
// the calibration phase so that each sensor can get a reading of how dark the
// line is and how light the ground is.  Improper calibration will result in
// poor readings.


//Config methods for line sensor


void sensorSetup(){
    // configure the sensors
  //Serial.println();
  //Serial.print("Calibration started");
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){2, 3, 4, 7, 8, 9, 12, 13}, SensorCount);
  //qtr.setEmitterPin(2);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

  // 2.5 ms RC read timeout (default) * 10 reads per calibrate() call
  // = ~25 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
 
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  Serial.begin(9600);
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  //Serial.print("Calibration done");
  Serial.println();
  delay(1000);
}


// The sensorCheck of the example reads the calibrated sensor values and uses
// them to estimate the position of a line. You can test this by taping a piece
// of 3/4" black electrical tape to a piece of white paper and sliding the
// sensor across it. It prints the sensor values to the serial monitor as
// numbers from 0 (maximum reflectance) to 1000 (minimum reflectance) followed
// by the estimated location of the line as a number from 0 to 5000. 1000 means
// the line is directly under sensor 1, 2000 means directly under sensor 2,
// etc. 0 means the line is directly under sensor 0 or was last seen by sensor
// 0 before being lost. 5000 means the line is directly under sensor 5 or was

void sensorCheck(){
    // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 5000 (for a white line, use readLineWhite() instead)
  posValue = qtr.readLineBlack(sensorValues);

  // print the sensor values as numbers from 0 to 1000, where 0 means maximum
  // reflectance and 1000 means minimum reflectance, followed by the line
  // position
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(posValue);

  delay(250);
}

//Get the linecommanders calculated position and sets direction + prints recommendation
void turnCommander() {
    posValue = qtr.readLineBlack(sensorValues);
     if(posValue == 0){
      Serial.println("Outside right");
      outsideRight();
    }
     if(posValue < 1000 && posValue > 0){
      Serial.println("Strong right");
      strongRight();
    }
     if(posValue > 1000 && posValue <2000){
      Serial.println("Slight right");
      slightRight();
    }
    if(posValue > 2000 && posValue <4000){
      Serial.println("Forward");
      forward();
    }
    if(posValue > 4000 && posValue <5500){
      Serial.println("Slight left");
      slightLeft();
    }
    if(posValue > 5500 && posValue <7000){
      Serial.println("Strong left");
      strongLeft();
    }
    if(posValue == 7000){
      Serial.println("Outside left");
      outsideLeft();
    }
    delay(50);
}
