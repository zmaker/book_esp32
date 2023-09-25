/* 
Autore: Paolo Aliverti
Listato 2.14 – Codice NON FUNZIONANTE per provare a leggere 
un pulsante e far lampeggiare un LED.

Collegare:
- un pulsante con pull down esterno da 10k sul pin 24
- led con res da 100 ohm sul pin 25
- led con res da 100 ohm sul pin 26
*/

void setup() {
  pinMode(24, INPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
}

void loop() {
  //lettura pulsante
  int v = digitalRead(24);
  digitalWrite(25, v);

  //blink
  digitalWrite(26, HIGH);
  delay(500);
  digitalWrite(26, LOW);
  delay (500);
}
