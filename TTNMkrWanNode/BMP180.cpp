/*
  bmp180.cpp
  Read data from BMP180
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "SFE_BMP180.h"
#include "debug.h"
#include "sleep.h"

SFE_BMP180::SFE_BMP180() {
//BME280::BME280(): bme() {
}

void BMP180::setup() {
  if (! pressure.begin()) {
    D_PRINTLN("Can't find BMP180 Sensor");
    blink(2000,2000);
  }

  // Weather monitoring profile
 // bme.setSampling(Adafruit_BME280::MODE_FORCED,
 //                 Adafruit_BME280::SAMPLING_X1, // temperature
 //                 Adafruit_BME280::SAMPLING_X1, // pressure
 //                 Adafruit_BME280::SAMPLING_X1, // humidity
 //                 Adafruit_BME280::FILTER_OFF   );
}

void BMP180::collect(CayenneLPP& lpp, int& payloadIndex) {
  float temp;

 // bme.takeForcedMeasurement();

status = pressure.startTemperature();
  if (status != 0)
  {
    // Wait for the measurement to complete:
    delay(status);

    // Retrieve the completed temperature measurement:
    // Note that the measurement is stored in the variable T.
    // Function returns 1 if successful, 0 if failure.

    status = pressure.getTemperature(T);
    if (status != 0)
    {

  //temp = bme.readTemperature();
  lpp.addTemperature(payloadIndex++, T);
  D_PRINTLN("T: " + String(T) + "°C");
  }
  
  status = pressure.startPressure(3);
      if (status != 0)
      {
        // Wait for the measurement to complete:
        delay(status);

        // Retrieve the completed pressure measurement:
        // Note that the measurement is stored in the variable P.
        // Note also that the function requires the previous temperature measurement (T).
        // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
        // Function returns 1 if successful, 0 if failure.

        status = pressure.getPressure(P,T);
        if (status != 0)
        {
    lpp.addBarometricPressure(payloadIndex++, P);
  //lpp.addBarometricPressure(payloadIndex++, bme.readPressure() / 100.0F);
  }

 //lpp.addRelativeHumidity(payloadIndex++, bme.readHumidity());

}
