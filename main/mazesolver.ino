//Choices [R,F], [L,F],[R,L] [R,L,F] =>> 0,1,2,3



uint8_t leftCount = 0;
uint8_t leftWayHome = 0;
uint8_t currentMazeId = 0;
uint8_t rigthWay = 0;


void currentMazeSide (){
    if(currentMazeId == 0){
        mazeRightSide();
    } else{
        mazeLeftSide(1);
    }
}



void mazeLeftSide(int choices){
    if (leftCount < 10) {

        if(choices > 0 ){
            //turn left
        } else{
            // go forward
        }
        leftCount ++;
        // go back to linecommander

    } else{
        if ((leftWayHome % 2) == 0){
            // turn right
            // go back to linecommander
        } else{
            // turn left
            // go back to linecommander
        }
    }
}

void mazeRightSide(){
Serial.println("mazeRight");
Serial.println(rigthWay);
switch (rigthWay) {
  case 0:
    strongLeft();
    delay(1500);
    rigthWay ++;
    break;
  case 1:
    strongLeft();
    delay(1500);
    rigthWay ++;
    break;
  case 2:
    forward();
    delay(500);
    rigthWay ++;
    break;
  case 3:
    forward();
    delay(500);
    rigthWay ++;
    break;
  case 4:
    strongLeft();
    delay(1500);
    rigthWay ++;
    break;
  case 5:
    strongLeft();
    delay(1500);
    rigthWay ++;
    break;
  case 6:
    forward();
    delay(500);
    rigthWay ++;
    break;
  case 7:
    strongRight();
    delay(1500);
    rigthWay ++;
    break;
  case 8:
    strongLeft();
    delay(1500);
    rigthWay ++;
    break;
}
    //L
    //R
    //F
    //L
    //L
    //F
    //R
    //L
}
