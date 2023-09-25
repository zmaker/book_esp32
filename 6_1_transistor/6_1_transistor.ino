/* 
Autore: Paolo Aliverti
Listato 6.1 – blink con transistor
*/

void setup() {
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(4, !digitalRead(4));
  delay(1000);  
}
