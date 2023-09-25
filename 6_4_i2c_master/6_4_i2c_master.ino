/* 
Autore: Paolo Aliverti
Listato 6.4 – I2C Master
*/
#include <Wire.h>

TwoWire i2c = TwoWire(0);
#define SDA_0 21
#define SCL_0 22
  
void setup() {
  Serial.begin(115200);
  Serial.println("I2C MASTER");
  i2c.begin(SDA_0 , SCL_0 , 100000);  
}

void loop() {
  i2c.requestFrom(7, 12);    //richiede 12 byte al device numero 7

  while (i2c.available()) { 
    char c = i2c.read(); 
    Serial.print(c);        
  }
  Serial.println("\n------------");

  delay(500);
}

