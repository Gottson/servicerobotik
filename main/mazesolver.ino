uint8_t leftCount = 0;
uint8_t leftWayHome = 0;


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
    //L
    //R
    //F
    //L
    //L
    //F
    //R
    //L
}
