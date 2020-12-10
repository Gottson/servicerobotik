//Called when line is lost. Sets custom drive patterns for a certain time.
void noLineHandler(){
  Serial.print("Lost line");

  
if (wallLeft() && !wallRight()) { 
  Serial.print("Wall left, Turn right");
  forward();
  delay(1000);
  strongRight();
  delay(1500);

}
if (!wallLeft() && wallRight()) { 
  Serial.print("Wall right, Turn left");
  forward();
  delay(1000);
  strongLeft();
  delay(1500);

}

if (wallInFront && wallRight() && wallLeft()){
  //BACKA
  //delay(3000);
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
