/**
 * 5.21 - triplo clic
 */

int tasto, prev_tasto;
unsigned long t0; //variabile per salvare il tempo di apertura della finestra
bool conteggio;  //variabile di controllo della finestra di conteggio
int click = 0;  //numero di click del tasto


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
    Serial.println("FDS");
    prev_tasto = tasto;

    //se il conteggio non è ancora attivo, lo faccio partire (apertura finestra)
    if (!conteggio) {
      conteggio = true;
      //salvo il tempo iniziale
      t0 = millis();
      Serial.println("start conteggio");
      //azzero i click
      click = 0;
    } 
  }  
  //individuo il fronte di discesa
  if (prev_tasto && !tasto) {
    Serial.println("FDD: fine conteggio");
    prev_tasto = tasto;
    click++;
  }
  //chiusura della finestra da 2s 
  if (conteggio && ((millis() - t0) > 2000) ){
    Serial.println("fine conteggio");
    conteggio = false;
    
    Serial.printf("click: %d\n", click);
    Serial.println("----------");
    if (click == 3) digitalWrite(4, !digitalRead(4));
  }
}

