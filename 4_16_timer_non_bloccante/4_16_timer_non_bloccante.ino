/* 
Autore: Paolo Aliverti
Listato 2.16 – blink non bloccante.

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
  if ((millis() – postit1) > 1000) {
    digitalWrite(26, !digitalRead(26));

    //aggiorno la nuova scadenza
    postit1 = millis();
  }
}
