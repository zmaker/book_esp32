/* 
Autore: Paolo Aliverti
Listato 2.15 – Codice creare un semplice “timer” utilizzando la funzione millis().

Collegare:
- led con res da 100 ohm sul pin 26
*/

//creo il mio post-it / timer
unsigned long postit1;

void setup() {
  pinMode(26, OUTPUT); 
 
  //segno l’ora iniziale sul post-it
  postit1 = millis();
}

void loop() {
  if ((millis() – postit1) > 3000) {
    digitalWrite(26, HIGH);
  }
}
