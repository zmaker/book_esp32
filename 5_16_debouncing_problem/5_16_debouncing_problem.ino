/**
 * 5.16 - Problemi con i pulsanti!?
 */

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Debouncing con delay");

  pinMode(4, OUTPUT);
  pinMode(16, INPUT);
}

void loop() {
  if (digitalRead(16)) {  
    Serial.println("clic");
    digitalWrite(4, !digitalRead(4));    
  }
  
}
