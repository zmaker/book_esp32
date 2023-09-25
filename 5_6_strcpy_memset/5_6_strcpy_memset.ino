/* 
Autore: Paolo Aliverti
Listato 3.6 – Esempio di codice per 
concatenare due array di caratteri
con memset e strcpy
*/

char str[20];

void setup(){
  Serial.begin(9600);  
  
  memset(str, '\0', sizeof(str));
  strcpy(str,  "Hello");  
  strcat(str, " World!");

  Serial.println(str);
  
}

void loop(){}
