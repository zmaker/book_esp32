/* 
Autore: Paolo Aliverti
Listato 2.26 – Utilizzo di due cicli for per realizzare un conteggio in avanti e poi all’indietro
*/
int i = 0;

void setup() {
  Serial.begin(115200);
  
  for (i = 0; i < 10; i++) {
    Serial.print(“i: “);  Serial.println(i);
  }
  for (i = 10; i >= 0; i--) {
    Serial.print(“i: “);  Serial.println(i);
  }
}

void loop() {}
