/* 
Autore: Paolo Aliverti
Listato 3.7 – Esempio di funzione con dichiarazione e implementazione
*/

//dichiarazione delle funzioni
int somma(int a, int b);

void setup(){
 Serial.begin(9600);  
  
 int a = 10;
 int b = 20;
 int r = somma(a, b);
 Serial.print("r: "); 
 Serial.println(r);
   
}

void loop(){}

//implementazione delle funzioni
int somma(int a, int b){
  int res = a + b;
  return res;
}
