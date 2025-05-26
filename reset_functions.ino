void resetHitter() {
  Serial.println("Reset Hitter");

  Serial.print("hitterSwitch: "); Serial.println(inputs[5]);
  while (!inputs[5]) {
    Myservo.write(0);
    delayMicroseconds(1000); //?
    inputs[5] = hitterSwitch.pressed();
  }
  Serial.println("hitter loaded");
  Myservo.write(90);
}

void resetRevolver() {
  int buttonStatusPressed = 0;
  int buttonStatusReleased = 0;
  int previousStatus = 1;

  Serial.println("Reset Revolver");

  buttonStatusPressed = homeSwitch.pressed();
  while (!buttonStatusPressed) { //Do this until the switch is activated
    if (previousStatus != buttonStatusPressed) {
      Serial.print("Home not pressed: ");
      Serial.println(buttonStatusPressed);
    }
    digitalWrite(dirPin, HIGH); //(HIGH = anti-clockwise / LOW = clockwise)
    digitalWrite(stepPin, HIGH);
    delay(2); //Delay to slow down speed of Stepper
    digitalWrite(stepPin, LOW);
    delay(2);
    previousStatus = buttonStatusPressed;
    buttonStatusPressed = homeSwitch.pressed();
  }

  previousStatus = 1;
  buttonStatusReleased = homeSwitch.released();
  while (!buttonStatusReleased || buttonStatusPressed) { //Do this until the switch is not activated
    if (previousStatus != buttonStatusPressed) {
      Serial.print("Home not released: ");
      Serial.println(buttonStatusReleased);
    }
    digitalWrite(dirPin, LOW);
    digitalWrite(stepPin, HIGH);
    delay(10); //More delay to slow even more while moving away from the switch
    digitalWrite(stepPin, LOW);
    delay(10);
    previousStatus = buttonStatusReleased;
    buttonStatusReleased = homeSwitch.released();
    buttonStatusPressed = homeSwitch.pressed();
  }
}

void resetConstruction() {
  int buttonStatus2 = 0;
  int previousStatus = 1;

  Serial.println("Reset Construction");

  buttonStatus2 = constructionSwitch.pressed();
  while (!buttonStatus2) { //Do this until the switch is activated
    if (previousStatus != buttonStatus2) {
      Serial.print("Construction not pressed: ");
      Serial.println(buttonStatus2);
    }
    digitalWrite(dirPin2, HIGH); //(HIGH = anti-clockwise / LOW = clockwise)
    digitalWrite(stepPin2, HIGH);
    delay(5); //Delay to slow down speed of Stepper
    digitalWrite(stepPin2, LOW);
    delay(5);
    previousStatus = buttonStatus2;
    buttonStatus2 = constructionSwitch.pressed();
  }

  previousStatus = 1;
  buttonStatus2 = constructionSwitch.released();
  while (!buttonStatus2) { //Do this until the switch is not activated
    if (previousStatus != buttonStatus2) {
      Serial.print("Construction not released: ");
      Serial.println(buttonStatus2);
    }
    digitalWrite(dirPin2, LOW);
    digitalWrite(stepPin2, HIGH);
    delay(10); //More delay to slow even more while moving away from the switch
    digitalWrite(stepPin2, LOW);
    delay(10);
    previousStatus = buttonStatus2;
    buttonStatus2 = constructionSwitch.released();
  }
}
