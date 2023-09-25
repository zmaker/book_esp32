int stato = 0;

void setup() {
  Serial.begin(115200);

  //led direzione "motore"
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(16, INPUT_PULLUP);  //BT apre
  pinMode(17, INPUT_PULLUP);  //BT chiude
  pinMode(18, INPUT_PULLUP);  //FC1
  pinMode(19, INPUT_PULLUP);  //FC2
}

void loop() {
  switch(stato) {
    case 0:
      chiuso();
      break;
    case 1:
      apertura();
      break;
    case 2:
      aperto();
      break;
    case 3:
      chiusura();
      break;
  }  
}

void chiuso(){  
  //attende pressione del pulsante di apertura
  if (!digitalRead(16)) {
    Serial.println("Apre");
    //accende il LED "avanti" (o attiva il motore)
    digitalWrite(4, HIGH);

    delay(300);
    stato = 1;
  }
}
void apertura(){
  //continuo ad aprire fino a che non incontro il fine corsa
  if (!digitalRead(18)) {
    Serial.println("FC1");
    //spegne il LED "avanti" 
    digitalWrite(4, LOW);

    delay(300);
    stato = 2;
  }
}
void aperto(){
  //attende pressione del pulsante di chiusura
  if (!digitalRead(17)) {
    Serial.println("Chiude");
    //accende il LED "indietro" (o attiva il motore)
    digitalWrite(5, HIGH);

    delay(300);
    stato = 3;
  }
}
void chiusura(){
  //continuo a chiudere fino a che non incontro il fine corsa
  if (!digitalRead(19)) {
    Serial.println("Chiusura");
    //spegne il LED "indietro" 
    digitalWrite(5, LOW);

    delay(300);
    stato = 0;
  }
}
