/* 
Autore: Paolo Aliverti
Accendere un LED con un pulsante
*/

void setup() {
  pinMode(23, INPUT);
  pinMode(25, OUTPUT);
}

void loop() {
  int v = digitalRead(23);
  digitalWrite(25, v);
}
