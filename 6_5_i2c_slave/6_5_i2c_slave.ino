/* 
Autore: Paolo Aliverti
Listato 6.5 – I2C Slave
*/
#include <Wire.h>

TwoWire i2c = TwoWire(0);
#define SDA_0 21
#define SCL_0 22

void setup() {  
  i2c.begin(7, SDA_0 , SCL_0 , 100000); //setup come slave rispondente all’indirizzo 7
  i2c.onRequest(trasmettiDati); 
}

void loop() {}

void trasmettiDati() {
  i2c.write("hello world!");
}
