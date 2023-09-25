/* 
Autore: Paolo Aliverti
Listato 2.30 – Esempio di utilizzo di un touch pin. 

Collegare:
- un jumper con placchetta di metallo al pin 2

*/
void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  int v = touchRead(2);
  Serial.println(v);
  delay(200);
}
