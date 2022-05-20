/**
 **************************************************
 *
 * @file        Anemometer-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/

#ifndef __ANEMOMETER__
#define __ANEMOMETER__

#define RPMToSpeed 4

#include "Arduino.h"

enum unit
{
    KMH,
    MPH,
    MS,
    KNOT
};

class Anemometer
{
  public:
    Anemometer(int _pin);
    float getWindSpeed(void);
    float getWindRPM(void);
    void setUnit(uint8_t _unit);
    uint8_t getUnit(void);

  protected:
    void initializeNative();

  private:
    int pin;
    uint8_t unit;
    float factors_unit[4] = {1.0, 0.62137, 0.27777, 0.53996};
};

#endif
