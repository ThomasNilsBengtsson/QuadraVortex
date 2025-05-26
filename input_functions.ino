
void readAllInputs() {
  inputs[0] = b1.pressed();
  inputs[1] = b2.pressed();
  inputs[2] = b3.pressed();
  inputs[3] = b4.pressed();
  inputs[4] = homeSwitch.pressed();
  inputs[5] = hitterSwitch.pressed();
  inputs[6] = revolverAngle.pressed();
  inputs[7] = constructionSwitch.pressed();
}

void readAllInputsHeldStatus() {
  inputs[0] = b1.held();
  inputs[1] = b2.held();
  inputs[2] = b3.held();
  inputs[3] = b4.held();
  inputs[4] = homeSwitch.held();
  inputs[5] = hitterSwitch.held();
  inputs[6] = revolverAngle.held();
  inputs[7] = constructionSwitch.held();
}

boolean isEvent() {
  boolean result = false;
  for (int i = 0; i < 8; i++) {
    if (inputs[i] == 1) {
      result = true;
    }
  }
  return result;
}

void printAllInputs() {
  Serial.print("input array: ");
  for (int i = 0; i < 8; i++) {
    Serial.print(inputs[i]);
  }
  Serial.println();
}

void printAllInputsStatus() {
  Serial.print("input array status: ");
  for (int i = 0; i < 8; i++) {
    Serial.print(inputsStatus[i]);
  }
  Serial.println();
}
