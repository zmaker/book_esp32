/* 
Autore: Paolo Aliverti
Listato 2.13 – Codice per accendere un LED con due pulsanti e l’istruzione OR (||).

Collegare:
- un pulsante con pull down esterno da 10k sul pin 22
- un pulsante con pull down esterno da 10k sul pin 23
- led con res da 100 ohm sul pin 25
*/

void setup() {
  pinMode(22, INPUT);
  pinMode(23, INPUT); 
  pinMode(25, OUTPUT);
}

void loop() {
  if (digitalRead(23) || digitalRead(22)) {
    //accendo il LED
    digitalWrite(25, HIGH); 
  } else {
    //spengo il LED
    digitalWrite(25, LOW); 
  }
}
