/* 
Autore: Paolo Aliverti
Listato 6.6 – I2C BMP280
*/
#include <Arduino.h>
#include <Wire.h>

#include <BMx280I2C.h>
#define I2C_ADDRESS 0x76
BMx280I2C bmx280(I2C_ADDRESS);

void setup() {
  
	Serial.begin(115200);
	Wire.begin();

	if (!bmx280.begin())	{
		Serial.println("begin() failed. check your BMx280 Interface and I2C Address.");
		while (1);
	}

	bmx280.resetToDefaults();

	//by default sensing is disabled and must be enabled by setting a non-zero
	//oversampling setting.
	//set an oversampling setting for pressure and temperature measurements. 
	bmx280.writeOversamplingPressure(BMx280MI::OSRS_P_x16);
	bmx280.writeOversamplingTemperature(BMx280MI::OSRS_T_x16);
}

void loop() {
	if (!bmx280.measure()) {
		Serial.println("could not start measurement, is a measurement already running?");
		return;
	}
	
	do {
		delay(100);
	} while (!bmx280.hasValue());

	Serial.print("Pressure: "); Serial.println(bmx280.getPressure());
	Serial.print("Temperature: "); Serial.println(bmx280.getTemperature());

	delay(1000);
}
