//Called when line is lost. Sets custom drive patterns for a certain time.
void noLineHandler(){
  Serial.println("Lost line");
if (wallLeft() && wallRight()){
  forward();
  delay(50);
  turnIgnore = false;
}
  
else if (wallLeft() && !wallRight()) { 
  Serial.println("Wall left, Turn right");
  stay();
  delay(1000);
  while (!wallInFront){
    Serial.println("Forward in wall left");
    forward();
    delay(50);
  }
  
  strongRight();
  delay(1500);

}
else if (!wallLeft() && wallRight()) { 
  Serial.println("Wall right, Turn left");
  stay();
  delay(1000);
  while (!wallInFront){
    Serial.println("Forward in wall right");
    forward();
    delay(50);
  }
  strongLeft();
  delay(1500);

}

else if (wallInFront() && wallRight() && wallLeft()){
  Serial.println("Wall right, left and front");
  rotateRight();
  delay(4000);
}
}

void turnHandler(){
  stay();
  Serial.println("turnHandler");
  delay(1000);
  
  if (wallLeft() && !wallRight()) { 
    Serial.println("Wall left -> strong right");
    strongRight();
    delay(1500);

    }
   else if (!wallLeft() && wallRight()) { 
     Serial.println("Wall right -> strong left");
    strongLeft();
    delay(1500);
    

    }
    else if (wallLeft() && wallRight()) { 
      Serial.println("Wall left and right. Go forward");
      forward();
      delay(50);
    }
  
  
}

void intersectionHandler(){
  Serial.println("intersectionhadler");
  //if (!wallLeft() && !wallRight()){
    Serial.println("T-section, turning right"); {
    strongRight();
    delay(2500);
  //  }
  }
}
