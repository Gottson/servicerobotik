//Choices [R,F], [L,F],[R,L] [R,L,F] =>> 0,1,2,3



uint8_t leftway = 0;
uint8_t leftWayHome = 0;
uint8_t currentMazeId = 0;
uint8_t rightWay = 0;
uint16_t nudge = 1000;


void currentMazeSide (){
    if(currentMazeId == 0){
        mazeRightSide();
    } else{
        mazeLeftSide(1);
    }
}

uint8_t getRightCount(){
  return rightWay;
}
uint8_t getLeftCount(){
  return leftway;
}

void incrementRight(){
  rightWay++;
}

void mazeLeftSide(int choices){
  Serial.println("mazeLeft");
  Serial.println(leftway);
    switch (leftway) {
        case 0:
            _left();
            leftway ++;
            break;
        case 1:
            forward();
            delay(100);
            leftway ++;
            break;
        case 2:
            _left();
            leftway ++;
            break;
        case 3:
            _left();
            leftway ++;
            break;
        case 4:
            _left();
            leftway ++;
            break;
        case 5:
            forward();
            delay(100);
            leftway ++;
            break;
        case 6:
            _left();
            leftway ++;
            break;
            //CASE SEX ÄR VÄSTERSVÄNGEN SOM INTE ÄR ETT VAL
        case 7:
            _left();
            leftway ++;
            break;
        
        case 8:
            forward();
            delay(100);
            leftway ++;
            break;
        case 9:
            _right();
            leftway ++;
            break;
        case 10:
            _left();
            leftway ++;
            break;
        case 11:
            _right();
            leftway ++;
            break;
    }
}
void mazeRightSide(){
Serial.println("mazeRight");
Serial.println(rightWay);
switch (rightWay) {
  case 0:
    _left();
    rightWay ++;
    break;
  case 1:
    _left();
    rightWay ++;
    break;
  case 2:
    forward();
    delay(100);
    rightWay ++;
    break;
  case 3:
    forward();
    delay(100);
    rightWay ++;
    break;
  case 4:
    _left();
    rightWay ++;
    break;
  case 5:
    _left();
    rightWay ++;
    break;
  case 6:
    forward();
    delay(100);
    rightWay ++;
    break;
  case 7:
    _right();
    rightWay ++;
    break;
  case 8:
    _left();
    currentMazeId++;
    break;
 
}
}
void _left(){
  strongLeft();
  delay(nudge);
  while(!getLine()){
    strongLeft();
  }
  //calibrateDrive();
}
void _right(){
  strongRight();
  delay(nudge);
  while(!getLine()){
    strongRight();
  }
  //calibrateDrive();
}
