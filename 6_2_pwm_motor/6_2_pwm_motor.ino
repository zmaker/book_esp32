/* 
Autore: Paolo Aliverti
Listato 6.6 – Controllo motore PWM 
*/
void setup() {
  int ch = 0;
  int freq = 1000;
  int res = 8;
  ledcSetup(ch, freq, res);

  int pin1 = 4;
  ledcAttachPin(pin1, ch);
}

void loop() {
  for (int i = 0; i < 256; i++) {
    ledcWrite(0, i);
    delay(5);  
  }
  for (int i = 255; i >= 0; i--) {
    ledcWrite(0, i);
    delay(5);  
  }
}
