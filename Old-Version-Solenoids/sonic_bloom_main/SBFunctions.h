
#ifndef _header_file_2
#define _header_file_2
#include "Sonic_Bloom_Vars.h"

class fclass 
{
public:
    fclass();

    void totalSetup();
    
    void read_photo_sensor_1();

    void extension();

    void read_photo_sensor_2();

    void solenoid_up();

    void solenoid_down();
};

//--------------------Function Definitions------------------//

void fclass::totalSetup(){
  pinMode(photoPin_1, INPUT);  // Photoresistor I
  pinMode(photoPin_2, INPUT); // Photoresistor II
  
  Serial.begin(9600); // Serial Monitor
  
  pinMode(speedPin, OUTPUT);   // DC Motor
  // pinMode(direction_1, OUTPUT);  // DC Motor
  // pinMode(direction_2, OUTPUT);  // DC Motor
  
  pinMode(SOLENOID_1, OUTPUT);
  pinMode(SOLENOID_2, OUTPUT);
  pinMode(SOLENOID_3, OUTPUT);
  pinMode(SOLENOID_4, OUTPUT);
}
void fclass::read_photo_sensor_1(){
  photoVal_1 = analogRead(A5); // Reads photoresistor I value.
  Serial.print(msg_1);
  Serial.println(photoVal_1); // Prints photoresistor I value.
}

void fclass::extension(){
      // digitalWrite(direction_1, HIGH);
      // digitalWrite(direction_2, LOW);
      // digitalWrite(speedPin, max_speed);
      
      digitalWrite(speedPin, HIGH); // DC Motor Starts.Discrete steps.
      delay(500);
      digitalWrite(speedPin, LOW);
      delay(500);
}

void fclass::read_photo_sensor_2(){
  photoVal_2 = analogRead(A3); // Reads photoresistor II value.
  Serial.print(msg_2);
  Serial.println(photoVal_2); // Prints photoresistor II value.
}

void fclass::solenoid_up(){        /* NOTE: To address current overload concern, 
                                    may have to activate solenoids one at a time. Fix later*/
      digitalWrite(SOLENOID_1, LOW);
      digitalWrite(SOLENOID_2, LOW);
      digitalWrite(SOLENOID_3, LOW);
      digitalWrite(SOLENOID_4, LOW);
}

void fclass::solenoid_down(){
      digitalWrite(SOLENOID_1, HIGH);
      digitalWrite(SOLENOID_2, HIGH);
      digitalWrite(SOLENOID_3, HIGH);
      digitalWrite(SOLENOID_4, HIGH);
}

extern fclass SBFunctions;

#endif // header_file_2
