/* 
Autore: Paolo Aliverti
Listato 3.4 – array e cicli
*/

void setup() {
  Serial.begin(115200);

  //un array di interi
  int buff[10]; 

  //array inizializzato con numeri pari
  for (int i = 0; i < 10; i++) {
    buff[i] = i*2;  
  }

  //stampo l'array:
  for (int i = 0; i < 10; i++) {
    Serial.printf("%d) Valore: %d \n", i, buff[i]);
  }

}

void loop() {}
