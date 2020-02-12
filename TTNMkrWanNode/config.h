/*
In this file you can easy config your device
*/

// Replace with keys obtained from TheThingsNetwork console
#define SECRET_APP_EUI "xxxxxxxxxxxxx"
#define SECRET_APP_KEY "yyyyyyyyyyyyyyyyyyyyyyy"


//Sensor configuration
//Comment and uncomment this to activate and deactivate specific sensor.
#define SENSOR_VOLTAGE
// #define SENSOR_MAXIM
// #define SENSOR_BME280
// #define SENSOR_BMP180 //the sensor not work yet
#define DEBUG_SERIAL


//Voltage reading config
#include <Arduino.h>
const uint8_t batteryPin = ADC_BATTERY;           // Battery pin
const uint8_t analogBits = 10;                    // ADC resolution
const uint16_t analogMax = (1 << analogBits)-1;   // Max value for ADC
const float divider = 3.018;                      // Voltage divider should be (680 + 330) / 330 == 3.061;
                                                  // set to 3.018 after calibration
const uint8_t overSampling = 8;                   // Read oversampling


//Wiring configuration

//LED Pin Config
const uint8_t ledPin    = PIN_LED;

//TTN JOIN Button config
const uint8_t resetPin  = 1;        // Reset button

//TPL Done pin
const uint8_t donePin = 2;  // TPL5110 Done pin
