#include <Stepper.h>
// Constants
int StepsPerRevolution = 2048;
int motSpeed = 8;
int dt = 100;

// Photoresistor Variables
int photoPin_1 = A5;
String msg_1 = "Photoresistor I value: ";
int thresh_val = 990;
int photoVal_1;

// Stepper Motor Variables
Stepper myStepper_1(StepsPerRevolution, 8, 10, 9, 11);
Stepper myStepper_2(StepsPerRevolution, 2, 4, 3, 5);

// SETUP
void setup() {
  Serial.begin(9600);
  myStepper_1.setSpeed(motSpeed); // Stepper Motor 1
  myStepper_2.setSpeed(motSpeed);
  pinMode(photoPin_1, INPUT);  // Photoresistor I
}

void loop() {
  photoVal_1 = analogRead(A5); // Reads photoresistor I value.
  Serial.print(msg_1);
  Serial.println(photoVal_1); // Prints photoresistor I value.

  if(photoVal_1 <= thresh_val) // Checks if light detect past threshold.
    { 
      myStepper_1.step(StepsPerRevolution/2);
      delay(dt);
      myStepper_2.step(-StepsPerRevolution/2);
      delay(dt);
    }
  else{}
}
