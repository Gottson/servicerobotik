void noLineHandler(){
  if (wallLeft && !wallRight) { // skapa en boolean, hasLine . tillåts bara att gå in i denna när hasLine == False
  forward();
  delay(1000);
  slightRight();
  delay(2000);
}
if (!wallLeft && wallRight) { // skapa en boolean, hasLine . tillåts bara att gå in i denna när hasLine == False
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
