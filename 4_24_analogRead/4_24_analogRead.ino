/* 
Autore: Paolo Aliverti
Listato 2.24 – lettura di un ingresso analogico (trimmer sul pin 34).
*/
void setup() {
  Serial.begin(115200);
  delay(3000);
  analogReadResolution(12);  //da 9 a 12
}

void loop() {
  int v = analogRead(34);
  Serial.println(v);
  delay(500);
}
