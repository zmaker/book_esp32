/* 
Autore: Paolo Aliverti
Listato 2.32 – Controllare un LED con un pin touch con calcolo automatico della soglia.

Collegare:
- un jumper con placchetta di metallo al pin 2
- un LED con resistore da 100 ohm al pin 4 

*/
int soglia = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Touch test");
  
  pinMode(4, OUTPUT);

  int valmedio = 0;
  for (int i = 0; i < 10; i++) {
   valmedio += touchRead(2);  
  }
  valmedio = valmedio / 10;
  soglia = (int)((float)valmedio * 0.85);
  Serial.print("vmedio: ");Serial.println(valmedio);
  Serial.print("soglia: ");Serial.println(soglia);
}

void loop() {
  int v = touchRead(2);
  if (v < soglia) {
    digitalWrite(4, HIGH);  
  } else {
    digitalWrite(4, LOW);    
  }
}
