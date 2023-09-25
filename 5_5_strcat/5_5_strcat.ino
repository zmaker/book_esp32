/* 
Autore: Paolo Aliverti
Listato 3.5 – Esempio di codice per 
concatenare due array di caratteri.
*/

char str[20] = "Hello";
char b[10] = " World!";

void setup() {
  Serial.begin(9600);  
  strcat(str, b);
  Serial.println(str);
}

void loop(){}
