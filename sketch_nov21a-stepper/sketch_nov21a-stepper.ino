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
Stepper myStepper(StepsPerRevolution, 8, 10, 9, 11);

// SETUP
void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed); // Stepper Motor 
  pinMode(photoPin_1, INPUT);  // Photoresistor I
}

void loop() {
  photoVal_1 = analogRead(A5); // Reads photoresistor I value.
  Serial.print(msg_1);
  Serial.println(photoVal_1); // Prints photoresistor I value.

  if(photoVal_1 <= thresh_val) // Checks if light detect past threshold.
    { 
      myStepper.step(StepsPerRevolution/2);
      delay(dt);
      myStepper.step(-StepsPerRevolution/2);
      delay(dt);
    }
  else{}
}
