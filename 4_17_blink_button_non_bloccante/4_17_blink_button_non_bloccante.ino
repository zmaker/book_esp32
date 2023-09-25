/* 
Autore: Paolo Aliverti
Listato 2.17 – Blink non bloccante con lettura di un pulsante.

Collegare:
- un pulsante con pull down esterno da 10k sul pin 24
- led con res da 100 ohm sul pin 25
- led con res da 100 ohm sul pin 26
*/

//creo il mio post-it / timer
unsigned long postit1;

void setup() {
  pinMode(24, INPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT); 
 
  //segno l’ora iniziale sul post-it
  postit1 = millis();
}

void loop() {
  //lettura pulsante
  int v = digitalRead(24);
  digitalWrite(25, v);

  if ((millis() – postit1) > 1000) {
    digitalWrite(26, !digitalRead(26));
    postit1 = millis();
  }
}
