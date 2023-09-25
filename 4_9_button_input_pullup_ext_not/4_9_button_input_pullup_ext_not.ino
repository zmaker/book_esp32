/* 
Autore: Paolo Aliverti
Accendere un LED con un pulsante 
Res. pullup esterno 10k su pulsante e uso di NOT (!)
*/

void setup() {
  pinMode(23, INPUT);
  pinMode(25, OUTPUT);
}

void loop() {
  int v = !digitalRead(23);
  digitalWrite(25, v);
}
