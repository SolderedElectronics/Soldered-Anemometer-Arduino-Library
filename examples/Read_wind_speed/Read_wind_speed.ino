/**
 **************************************************
 *
 * @file        Read_wind_speed.ino
 * @brief       Example reading wind speed and setting 
 *              measuring unit
 *
 *
 *
 * @authors     Goran Juric @ soldered.com
 ***************************************************/

#include "Anemometer-SOLDERED.h"

#define ANEMOMETER_PIN 9 // Set anemometer pin to 9

Anemometer anemometer(ANEMOMETER_PIN); // Make andemometer object and specify pin on which is connected

void setup()
{
  Serial.begin(115200); // Begin serial communication with PC with 

  anemometer.setUnit(MS); // Choose unit to return wind speed (KMH, MPH, KNOT, MS)
}

void loop()
{
  Serial.print("Anemometer reading: "); // Print message
  Serial.print(anemometer.getWindSpeed());  // Get wind speed
  Serial.println(" m/s."); // Print message
  Serial.print("Anemometer reading: "); // Print message
  Serial.print(anemometer.getWindRPM()); // Get anemometers RPM
  Serial.println(" RPM.\n"); // Print message
  delay(1000); // Delay before next measure
}
