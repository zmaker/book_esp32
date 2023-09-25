/**
 * 5.19 - FDS e FDD
 */

int tasto, prev_tasto;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("FDS FDD");

  pinMode(4, OUTPUT);
  pinMode(16, INPUT);
}

void loop() {  
  tasto = digitalRead(16);

  //individuo il fronte di salita
  if (!prev_tasto && tasto) {
    Serial.println("off-on - salita");    
  }  
  //individuo il fronte di discesa
  if (prev_tasto && !tasto) {
    Serial.println("on-off - discesa");
  }
  //salvo il valore di stato in prev_stato
  prev_tasto = tasto;
}


