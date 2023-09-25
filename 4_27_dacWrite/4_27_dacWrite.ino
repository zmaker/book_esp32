/* 
Autore: Paolo Aliverti
Listato 2.27 – Generare un’onda triangolare con i DAC della scheda ESP32.
*/
void setup() {}

void loop() {
  for (int i = 0; i < 256; i++) {
    dacWrite(25, i);
    delay(1);
  }
  for (int i = 255; i >= 0; i--) {
    dacWrite(25, i);
    delay(1);
  }
}
