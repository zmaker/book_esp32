/* 
Autore: Paolo Aliverti
Listato 2.23 – Invio di caratteri su porta seriale per controllare lo stato di un pin.
*/
void setup() {
  Serial.begin(115200);
  pinMode(25, OUTPUT);
  Serial.println("Serial read()");
}

void loop() {
  if (Serial.available()) {
    char comando = Serial.read();
    if (comando == 'a') {
      digitalWrite(25, HIGH);
      Serial.println("ON 25");
    }
    if (comando == 's') {
      digitalWrite(25, LOW);
      Serial.println("OFF 25");
    }
  }
}
