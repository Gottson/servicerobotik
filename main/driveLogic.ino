//Called when line is lost. Sets custom drive patterns for a certain time.
void noLineHandler(){
  Serial.println("Lost line");
if (wallLeft() && wallRight() && !wallInFront()){
  Serial.println("Wall left and right, clear forward, go forward");
  forward();
  delay(50);
  //turnIgnore = false;
}
  
else if (wallLeft() && !wallRight()) { 
  Serial.println("Wall left, stay");
  stay();
  delay(1000);
  while (!wallInFront()){
    Serial.println("Forward in wall left");
    forward();
    delay(50);
  }
  Serial.println("Wall right, strong right");
  //forward();
  //delay(500);
  strongRight();
  delay(1500);

}
else if (!wallLeft() && wallRight()) { 
  Serial.println("Wall right, Stay");
  stay();
  delay(1000);
  while (!wallInFront()){
    Serial.println("Forward in wall right");
    forward();
    delay(50);
  }
  Serial.println("Wall right, Strong left");
  //forward();
  //delay(500);
  strongLeft();
  delay(1500);

}

else if (wallInFront() && wallRight() && wallLeft()){
  Serial.println("Wall right, left and front");
  stay();
  delay(5000);
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
