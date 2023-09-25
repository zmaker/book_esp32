int stato = 0;

void setup() {
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

}
void apertura(){
  
}
void aperto(){
  
}
void chiusura(){
  
}
