//Stepper motor 1

void moveToAngle() {
  // HACKME: this is to use switches instead of angles
  int toMove = int(abs((angle - currentAngle) / 90));

  Serial.print("currentAngle: "); Serial.print(currentAngle);
  Serial.print(" | angle: "); Serial.println(angle);
  Serial.print("Move positions: "); Serial.println(toMove);

  while ( currentAngle != angle ) {
    if ( currentAngle < angle) {
      digitalWrite(dirPin, HIGH);

      // HACKME
      //toMove++;

      n = angle - currentAngle;
      numstep = 2 * n / stepPerAngle;
    }
    else if ( currentAngle > angle) {
      digitalWrite(dirPin, LOW);

      n = currentAngle - angle;
      if ( angle == 0) {
        n = currentAngle;
      }
      numstep = 2 * n / stepPerAngle;
    }

    Serial.print("Move positions (corr): "); Serial.println(toMove);

    //for (int x = 0; x < numstep; x++) {
    for (int i = 0; i < toMove; i++) {
      while (!revolverAngle.pressed()) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
      }

      Serial.print("Reached vortex: "); Serial.println(i);
      delay(1000);

      //while (!revolverAngle.released()) {
      for(int j = 0; j < 10; j++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(1000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(1000);
      }
    }

    readAllInputsHeldStatus();
    printAllInputsStatus();

    delay(1000);
    Serial.println("measurement after delay");
    readAllInputsHeldStatus();
    printAllInputsStatus();
    
    currentAngle = angle;
  }
}

//Stepper motor 2
void moveToAngle2() {
  while ( currentAngle2 != angle2 ) {
    if ( currentAngle2 < angle2) {
      digitalWrite(dirPin2, HIGH);
      n2 = angle2 - currentAngle2;
      numstep2 = 6 * n2 / stepPerAngle2;
    }
    else if ( currentAngle2 > angle2) {
      digitalWrite(dirPin2, LOW);
      n2 = currentAngle2 - angle2;
      if ( angle2 == 0) {
        n2 = currentAngle2;
      }
      numstep2 = 6 * n2 / stepPerAngle2;
    }

    for (int x = 0; x < numstep2; x++) {
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(1000);
    }
    currentAngle2 = angle2;
  }
}
