struct {
  char nome[20];
  char via[30];
  int cap;
} addr;

void setup() {
  Serial.begin(115200);

  addr.cap = 12345;
  strncpy(addr.nome, "Milano", 7);

  char strada[] = "Via Mazzini, 12";
  strncpy(addr.via, strada, sizeof(strada));

  Serial.printf("%s a %s ( %d )\n", addr.via, addr.nome, addr.cap);
}

void loop() {
  // put your main code here, to run repeatedly:

}
