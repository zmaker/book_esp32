/* 
Autore: Paolo Aliverti
Listato 3.1 – uso di sizeof.
*/

void setup() {
  Serial.begin(115200);
  int n = 123;

  Serial.printf("Valore di n: %d, dimensioni: %d\n", n, sizeof(n));
}

void loop() {}
