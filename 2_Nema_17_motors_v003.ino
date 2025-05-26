//Servo motor
#include<EduIntro.h>

ServoMotor Myservo(7);

// Stepper motor 1 defines pins numbers
const int stepPin = 10;
const int dirPin  = 9;
int steps; //Used to set HOME position after Homing is completed

// Stepper motor 2 defines pins numbers
const int stepPin2 = 12;
const int dirPin2  = 11;
int steps2; //Used to set HOME position after Homing is completed

// Button
Button b1(A0);
Button b2(A1);
Button b3(A2);
Button b4(A3);
Button hitterSwitch(A4);
Button revolverAngle(4);
Button homeSwitch(A5);
Button constructionSwitch(2);

//Stepper motor 1
int currentAngle = 0;
int angle = 0;
float stepPerAngle = 1.8; // full step = 1.8
int   numstep;
int n;

//Stepper motor 2
int currentAngle2 = 0;
int angle2 = 0;
float stepPerAngle2 = 1.8; // full step = 1.8
int   numstep2;
int n2;

//int steps; //Used to set Home position after Homing is completed


int inputs[] = {0, 0, 0, 0, 0, 0, 0, 0}; // store all inputs
int inputsStatus [] = {0, 0, 0, 0, 0, 0, 0, 0};


void setup() {

  Serial.begin(9600);

  delay(10000);

  while (!Serial) {};

  // Stepper motor 1 Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, HIGH);

  // Stepper motor 2 Sets the two pins as Outputs
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  digitalWrite(dirPin2, HIGH);

  resetHitter();
  resetRevolver();
  resetConstruction();

  //Stepper motor 1
  steps = 0; //Reset position variable to zero

  //Stepper motor 2
  steps2 = 0; //Reset position variable to zero

}

void loop() {

  readAllInputs();

  int buttonCase = inputs[0] << 3 | inputs[1] << 2 | inputs[2] << 1 | inputs[3];

  if (isEvent()) {
    printAllInputs();
    Serial.print("buttonCase: ");
    Serial.println(buttonCase);
  }

  switch (buttonCase) {
    case 1:
      // XXX
      angle = -270;
      angle2 = -270;
      resetHitter();
      moveToAngle();
      moveToAngle2();
      delay(2000);
      triggerHitter();
      break;
    case 2:
      // XXX
      angle = -180;
      angle2 = -180;
      resetHitter();
      moveToAngle();
      moveToAngle2();
      delay(2000);
      triggerHitter();
      break;
    case 4:
      // XXX
      angle = -90;
      angle2 = -90;
      resetHitter();
      moveToAngle();
      moveToAngle2();
      delay(2000);
      triggerHitter();
      break;
    case 8:
      // XXX
//      resetHitter();
//      resetRevolver();
      angle = 0;
//      currentAngle = 0;
      angle2 = 0;
//      currentAngle2 = 0;
      resetHitter();
      moveToAngle();
      moveToAngle2();

//      resetConstruction();
      delay(2000);

//      resetHitter();
      triggerHitter();
      break;
  }
}



void triggerHitter() {
  Serial.println("hitter trigger");
  Myservo.write(0);
  delay(1000); // XXX: this is the time you have to figure out how much it will be
  Myservo.write(90);
}
