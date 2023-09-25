/* 
Autore: Paolo Aliverti
Listato 3.7 – Esempio di funzione con dichiarazione e implementazione
*/

void f(int *p);

void setup(){
 Serial.begin(9600);  
  
 int v = 10;
 Serial.print("v: "); 
 Serial.println(v);
 
 f(&v);

 Serial.print("v: "); 
 Serial.println(v);
  
}

void loop(){}

void f(int *p) {
   *p = *p * 10;  
}
