/* 
Autore: Paolo Aliverti
Listato 7.25 – Server BLE con contatore
*/
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID        "0000180F-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_UUID "00002A19-0000-1000-8000-00805F9B34FB"

BLEServer *server;
BLEService *service;
BLECharacteristic *caratteristica;

bool CONNESSO = false;
uint8_t livello_batteria = 0;

class EventiBLE: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    CONNESSO = true;    
  }

  void onDisconnect(BLEServer* pServer) {    
    CONNESSO = false;    
  }
};


void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 BLE Server");
  
  // Inizializza il BLE
  BLEDevice::init("ESP32 BLE Server");
  
  // Crea il server BLE
  server = BLEDevice::createServer();
  server->setCallbacks(new EventiBLE());

  // Crea il servizio
  service = server->createService(SERVICE_UUID);

  // Crea la caratteristica con il contatore
  caratteristica = service->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_NOTIFY
                    );

  // Abilita le notifiche per la caratteristica
  caratteristica->addDescriptor(new BLE2902());

  // Avvia il servizio
  service->start();

  // Avvia l'annuncio del servizio
  BLEAdvertising *advertising = server->getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
  advertising->start();
}


void loop() {
  if (CONNESSO) {
    livello_batteria++;
    if (livello_batteria >= 100) livello_batteria = 0;
    
    // Aggiorna la caratteristica e manda la notifica
    caratteristica->setValue((uint8_t*)&livello_batteria, sizeof(livello_batteria));
    caratteristica->notify();
  }

  delay(1000);
}
