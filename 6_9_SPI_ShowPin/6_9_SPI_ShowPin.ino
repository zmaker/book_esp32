/* 
Autore: Paolo Aliverti
Listato 6.9 – SPI pin
*/
void setup() {
  Serial.begin(115200);
  Serial.println("MOSI\tMISO\tSCK\tSS");
  Serial.printf("%d\t%d\t%d\t%d\n", MOSI, MISO, SCK, SS);
}

void loop() {
  // put your main code here, to run repeatedly:
}
