//Choices [R,F], [L,F],[R,L] [R,L,F] =>> 0,1,2,3



uint8_t leftway = 0;
uint8_t leftWayHome = 0;
uint8_t currentMazeId = 0;
uint8_t rightWay = 0;
uint8_t nudge = 500;


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
void incrementRight(){
  rightWay++;
}

void mazeLeftSide(int choices){
    switch (leftway) {
        case 0:
            strongLeft();
            delay(nudge);
            leftway ++;
            break;
        case 1:
            forward();
            delay(100);
            leftway ++;
            break;
        case 2:
            strongLeft();
            delay(nudge);
            leftway ++;
            break;
        case 3:
            strongLeft();
            delay(nudge);
            leftway ++;
            break;
        case 4:
            strongLeft();
            delay(nudge);
            leftway ++;
            break;
        case 5:
            forward();
            delay(100);
            leftway ++;
            break;
        case 6:
            strongLeft();
            delay(nudge);
            leftway ++;
            break;
        case 7:
            forward();
            delay(100);
            leftway ++;
            break;
        case 8:
            strongRight();
            delay(nudge);
            leftway ++;
            break;
        case 9:
            strongLeft();
            delay(nudge);
            leftway ++;
            break;
        case 10:
            strongRight();
            delay(nudge);
            leftway ++;
            break;
    }

void mazeRightSide(){
Serial.println("mazeRight");
Serial.println(rightWay);
switch (rightWay) {
  case 0:
    strongLeft();
    delay(nudge);
    rightWay ++;
    break;
  case 1:
    strongLeft();
    delay(nudge);
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
    strongLeft();
    delay(nudge);
    rightWay ++;
    break;
  case 5:
    strongLeft();
    delay(nudge);
    rightWay ++;
    break;
  case 6:
    forward();
    delay(100);
    rightWay ++;
    break;
  case 7:
    strongRight();
    delay(nudge);
    rightWay ++;
    break;
  case 8:
    strongLeft();
    delay(nudge);
    rightWay ++;
    break;
}
}
