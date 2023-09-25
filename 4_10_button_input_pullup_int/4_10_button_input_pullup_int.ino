/* 
Autore: Paolo Aliverti
Accendere un LED con un pulsante 
Res. pullup interno
*/

void setup() {
  pinMode(23, INPUT_PULLUP);
  pinMode(25, OUTPUT);
}

void loop() {
  int v = !digitalRead(23);
  digitalWrite(5, v);
}
