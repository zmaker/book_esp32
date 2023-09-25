/* 
Autore: Paolo Aliverti
Listato 3.2 – puntatori.
*/

void setup() {
  Serial.begin(115200);

  //una variabile
  int n = 123; 
  
  //puntatore a variabile di tipo int
  int *ptr;

  //ricavo l'indirizzo di n e lo assegno al puntatore
  ptr = &n;

  //stampo il contenuto puntato dal ptr
  Serial.printf("Valore puntato: %d indirizzo: %p\n", *ptr, ptr);

  //modifico il valore:
  *ptr = 456;

  //stampo il contenuto puntato dal ptr
  Serial.printf("Valore modificato: %d indirizzo: %p\n", *ptr, ptr);

}

void loop() {}
