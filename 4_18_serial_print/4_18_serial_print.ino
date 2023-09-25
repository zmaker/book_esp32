/* 
Autore: Paolo Aliverti
Listato 2.18 – Codice per un inviare messaggi al Serial Monitor.
*/
int counter = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello ESP32!");
}

void loop() {
  Serial.print("Count: ");
  Serial.println(counter);
  counter++;
  delay(1000);
}
