/* 
Autore: Paolo Aliverti
Uso di if-else

Collegare:
- un pulsante con pull down esterno da 10k sul pin 23
- led con res da 100 ohm sul pin 25
*/

void setup() {
  pinMode(23, INPUT);
  pinMode(25, OUTPUT);
}

void loop() {
  if (digitalRead(23)) {
    //accendo il LED
    digitalWrite(25, HIGH); 
  } else {
    //spengo il LED
    digitalWrite(25, LOW); 
  }
}
