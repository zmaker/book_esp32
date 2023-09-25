/* 
Autore: Paolo Aliverti
Listato 3.9 – enumerazioni

Collegare:
- led con res da 100 ohm sul pin 4
*/

enum livello_pwm {spento, basso, medio, alto} lev;

void setup() {
  Serial.begin(115200);
  Serial.println("enum");
  int ch = 0;
  int freq = 1000;
  int res = 8;
  ledcSetup(ch, freq, res);  
  ledcAttachPin(4, ch);

  analogReadResolution(10);  //0-1023
}

void loop() {
  int v = analogRead(34);
  Serial.println(v);
  delay(300);
  if (v < 200) lev = spento;
  else if (v < 400) lev = basso;
  else if (v < 800) lev = medio;
  else lev = alto;
  
  
  if (lev == spento) {
    Serial.println("off");
    ledcWrite(0, 0);
  }
  if (lev == basso) {
    ledcWrite(0, 70);
    Serial.println("basso");
  }
  if (lev == medio) {
    ledcWrite(0, 140);
    Serial.println("medio");
  }
  if (lev == alto) {
    ledcWrite(0, 255);  
    Serial.println("on");
  }
  
}
