/**
 **************************************************
 *
 * @file        Anemometer-SOLDERED.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/


#include "Anemometer-SOLDERED.h"

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
Anemometer::Anemometer(int _pin)
{
    pin = _pin;
    initializeNative();
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void Anemometer::initializeNative()
{
    pinMode(pin, INPUT);
}

/**
 * @brief                   Function which gets rotation speed.
 * 
 * @return                  Anemometer rotation speed in RPM
 */
float Anemometer::getWindRPM()
{
    uint32_t low, high;
    low = pulseIn(pin, LOW, 1000000);
    if(low)
    {
        high = pulseIn(pin, HIGH, 1000000);
        return (1.0 / (high + low) * 1000000) / 16.0;
    }
    else
    {
        return 0.0;
    }
}

/**
 * @brief                   Funtion which chooses unit for measure.
 * 
 * @param uint8_t _unit     Measuring unit (KMH,MPH,MS,KNOT)
 */
void Anemometer::setUnit(uint8_t _unit)
{
    unit = _unit;
}

/**
 * @brief                   Funtion which gets unit for measure.
 * 
 * @return                  Measuring unit (KMH = 0,MPH = 1,MS = 2,KNOT = 3)
 */
uint8_t Anemometer::getUnit()
{
    return unit;
}

/**
 * @brief                   Funtion which gets wind speed.
 * 
 * @return                  Wind speed in choosen unit.
 */
float Anemometer::getWindSpeed()
{
    float rpm = getWindRPM();
    return (rpm * factors_unit[unit] * RPMToSpeed);
}