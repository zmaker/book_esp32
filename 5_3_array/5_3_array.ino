/* 
Autore: Paolo Aliverti
Listato 3.3 – array
*/

void setup() {
  Serial.begin(115200);

  //un array di interi
  int buff[10]; 

  //array inizializzato
  int val[] = {1,3,5,7,9};

  //leggo un valore
  Serial.printf("Valore: %d \n", val[0]);
  Serial.printf("Valore: %d \n", val[1]);
  Serial.printf("Valore: %d \n", val[2]);

  //assegno un valore
  buff[0] = 12;
  Serial.printf("Valore: %d \n", buff[0]);

}

void loop() {}

