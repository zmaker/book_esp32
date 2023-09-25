/* 
Autore: Paolo Aliverti
Accendere un LED con un pulsante - res. pulldown interno
*/

void setup() {
  pinMode(23, INPUT_PULLDOWN);
  pinMode(25, OUTPUT);
}

void loop() {
  int v = digitalRead(23);
  digitalWrite(25, v);
}
