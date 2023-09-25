/* 
Autore: Paolo Aliverti
Listato 2.20– Stampa con formattazione sul Serial Monitor.
*/
void setup() {
  Serial.begin(115200);
  Serial.println(123, DEC);
  Serial.println(123, BIN);
  Serial.println(123, OCT); 
  Serial.println(123, HEX);
  Serial.println(3.14159, 0);
  Serial.println(3.14159, 2);
  Serial.println(3.14159, 4);
}

void loop() {}
