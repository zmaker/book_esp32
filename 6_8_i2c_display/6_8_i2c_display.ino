/* 
Autore: Paolo Aliverti
Listato 6.8 – I2C Display SSD1306
*/
#include <Arduino.h>
#include <Wire.h>

#include <BMx280I2C.h>
#define I2C_ADDRESS 0x76
BMx280I2C bmx280(I2C_ADDRESS);

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
	Serial.begin(115200);
	Wire.begin();

	if (!bmx280.begin())	{
		Serial.println("Errore hardware BMx280");
		while (1);
	}

	bmx280.resetToDefaults();
	bmx280.writeOversamplingPressure(BMx280MI::OSRS_P_x16);
	bmx280.writeOversamplingTemperature(BMx280MI::OSRS_T_x16);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("Verifica i collegamenti del display!");
    while(1); //stop
  }

  //inizializza il display
  display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE);   
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.clearDisplay();
  display.display();
}

void loop() {
	if (!bmx280.measure()) {
		Serial.println("could not start measurement, is a measurement already running?");
		return;
	}
	
	do {
		delay(100);
	} while (!bmx280.hasValue());

  //visualizza la temperatura
  display.clearDisplay();
  display.setCursor(1, 1);
  display.print(bmx280.getTemperature());
  display.print(" C");

  int x = (int)constrain(bmx280.getTemperature(), 0, 100);
  display.drawRect(0, 20, 100, 20, SSD1306_WHITE);
  display.fillRect(0, 20, x, 20, SSD1306_WHITE);
  display.display(); 

	Serial.print("Pressure: "); Serial.println(bmx280.getPressure());
	Serial.print("Temperature: "); Serial.println(bmx280.getTemperature());

	delay(1000);
}
