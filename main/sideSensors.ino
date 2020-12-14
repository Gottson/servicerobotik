int basespeedaa = 105;
int basespeedbb = 105;

double kp = 2;
double kd = 1;

//Increasing the maxspeed can damage the motors - at a value of 255 the 6V motors will receive 7,4 V 
const uint8_t maxspeedaa = 120;
const uint8_t maxspeedbb = 120;
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

void Wall_p_cont(){
  int error = 12-hc.dist(0);
  int motorSpeed = error*kp;
  int speeda = basespeedaa + motorSpeed;
  int speedb = basespeedaa - motorSpeed;

    if (speeda > maxspeedaa) {
    speeda = maxspeedaa;
  }
  if (speedb > maxspeedbb) {
    speedb = maxspeedbb;
  }
  if (speeda < 90) {
    speeda = 90;
  }
  if (speedb < 90) {
    speedb = 90;
  } 
   //motorspeedb = 180 - motorspeedb;
   speeda = 180 - speeda;
   Serial.println(speeda);
   Serial.println(speedb);
   Serial.println(hc.dist(0));
   leftServo.write(speeda);
   rightServo.write(speedb);
}
