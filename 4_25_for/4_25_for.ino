/* 
Autore: Paolo Aliverti
Listato 2.25 – Utilizzo di un ciclo for per stampare una sequenza di numeri.
*/
void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 10; i++) {
    Serial.print(“i: “);  
    Serial.println(i);
  }
}

void loop() {}
