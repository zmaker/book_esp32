/* 
Autore: Paolo Aliverti
Far lampeggiare un LED
*/

void setup() {
  pinMode(25, OUTPUT);
}

void loop() {
  digitalWrite(25, HIGH);
  delay(500);
  digitalWrite(25, LOW);
  delay (500);
}
