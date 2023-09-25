/**
 * 5.20 - Long press
 */

int tasto, prev_tasto;
unsigned long t0;

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
    Serial.println("FDS: inizio conteggio");
    t0 = millis();
  }  
  //individuo il fronte di discesa
  if (prev_tasto && !tasto) {
    Serial.println("FDD: fine conteggio");
    long tempo_trascorso = millis() - t0;
    Serial.printf("tempo pressione: %d\n", tempo_trascorso);    

    if (tempo_trascorso > 2000) {
      Serial.println("Azione Speciale attivata!");
      digitalWrite(4, !digitalRead(4));
    }
  }
  //salvo il valore di stato in prev_stato
  prev_tasto = tasto;
}

