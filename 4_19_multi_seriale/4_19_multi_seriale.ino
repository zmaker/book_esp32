/* 
Autore: Paolo Aliverti
Listato 2.19 – Riassegnazione dei pin delle seriali.
*/
void setup() {
  Serial.begin(115200);
  Serial1.begin(115200, SERIAL_8N1, 25, 26); //RX, TX
  Serial2.begin(115200, SERIAL_8N1, 12, 13); //RX, TX
}

void loop() {}
