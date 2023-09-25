/* 
Autore: Paolo Aliverti
Listato 2.31 – Controllare un LED con un pin touch.

Collegare:
- un jumper con placchetta di metallo al pin 2
- un LED con resistore da 100 ohm al pin 4 

*/
int soglia = 500;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Touch LED");
  
  //imposto il pin 4 come uscita
  pinMode(4, OUTPUT);
}

void loop() {
  int v = touchRead(2);
  if (v < soglia) {
    digitalWrite(4, HIGH);  
  } else {
    digitalWrite(4, LOW);    
  }
}
