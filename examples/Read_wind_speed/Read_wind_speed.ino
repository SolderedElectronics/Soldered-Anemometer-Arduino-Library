/**
 **************************************************
 *
 * @file        Read_wind_speed.ino
 * @brief       Example reading wind speed and setting 
 *              measuring unit
 *
 * @link        product: www.soldered.com/333196
 *
 * @authors     Goran Juric @ soldered.com
 ***************************************************/

#include "Anemometer-SOLDERED.h"

#define ANEMOMETER_PIN 9 // Set anemometer pin to 9

Anemometer anemometer(ANEMOMETER_PIN); // Make anemometer object and specify pin on which is connected
                                       // This anemometer has rotary encoder attached to rotating shaft and
                                       // optical sensor which senses rotation. More about rotary encoder
                                       // can be found here: https://en.wikipedia.org/wiki/Rotary_encoder
                                       // As shaft is rotating, rotary encoder is interrupting light source
                                       // and optical sensor senses pulses of light and measures lasting of
                                       // them and converts that pulses into rotating speed which is later
                                       // converted to wind speed in desired unit. Because some pulses are 
                                       // too long (when wind blows really slow) MCU will ignore low speeds
                                       // of wind.

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
