/* 
Autore: Paolo Aliverti
Accendere un LED con un pin GPIO
*/

void setup() {
  pinMode(25, OUTPUT);  //imposto il pin come uscita
}

void loop() {
  digitalWrite(25, HIGH); //accendo il pin
}
