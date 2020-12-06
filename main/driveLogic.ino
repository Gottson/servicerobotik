//Called when line is lost. Sets custom drive patterns for a certain time.
void noLineHandler(){
  if (wallLeft && !wallRight) { 
  forward();
  delay(1000);
  slightRight();
  delay(2000);
}
if (!wallLeft && wallRight) { 
  forward();
  delay(1000);
  slightLeft();
  delay(2000);
}

if (wallInFront && wallRight && wallLeft){
  rotateLeft();
  delay(3000);
}
}
