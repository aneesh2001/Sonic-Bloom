
// C++ code 
#include "SBFunctions.h"

void setup()
{
  SBFunctions.totalSetup();
}

void loop()
{
  /* PHASE I*/
  SBFunctions.read_photo_sensor_1();

  if((photoVal_1 < 400) && (photoVal_2 > 400))    // Placeholder value for 'light'. Needs testing.  
    {
      SBFunctions.extension(); // Extension by Rack & Pinion.
    }
    
  else
    {
      digitalWrite(speedPin, LOW);
    }
  
  
  /* PHASE II*/
  SBFunctions.read_photo_sensor_2();
  
  if(photoVal_2 >= 400)     // Placeholder value for 'light'. Needs testing. 
    {
      SBFunctions.solenoid_up(); // Solenoids "up"
    }
  else      
    {
      SBFunctions.solenoid_down(); // Solenoids "down"
    }
  
}
