#include <Arduino.h>
#include "LoRa_PINS.h"

void setupLoRa();

int counter = 0;

void setup() {
  Serial.begin(115200);
  // while (!Serial);
  Serial.println("LoRa Sender");

  setupLoRa();
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}

void setupLoRa() {
  SPI.setMISO(LORA_MISO);
  SPI.setMOSI(LORA_MOSI);
  SPI.setSCLK(LORA_SCK);
  SPI.setSSEL(LORA_NSS);

  LoRa.setPins(LORA_NSS, LORA_NRESET, LORA_DIO0);

  LoRa.setTxPower(14);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setSpreadingFactor(7);
  LoRa.setCodingRate4(5);
  LoRa.setPreambleLength(8);

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}





// void setup() {
//   // Inicializa la comunicación serial a 9600 bps.
//   Serial.begin(115200);
// }

// void loop() {
//   // Lista de todos los pines disponibles, excluyendo los pines de LoRa.
//   int pins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 17, 18, 19, 20, 21, 22, 23, 24, 25, 31, 34, 36, 37};

//   // Itera sobre cada pin en la lista.
//   for (int i = 0; i < sizeof(pins) / sizeof(pins[0]); i++) {
//     int pin = pins[i];

//     // Configura el pin actual como salida.
//     pinMode(pin, OUTPUT);

//     // Enciende el pin actual.
//     digitalWrite(pin, HIGH);

//     // Imprime en la consola serial el pin que se está encendiendo.
//     Serial.print("Encendiendo pin: ");
//     Serial.println(pin);

//     // Espera un segundo.
//     delay(1000);

//     // Apaga el pin actual.
//     digitalWrite(pin, LOW);

//     // Imprime en la consola serial el pin que se está apagando.
//     Serial.print("Apagando pin: ");
//     Serial.println(pin);

//     // Espera un segundo antes de pasar al siguiente pin.
//     delay(1000);
//   }

//   // Detiene el bucle para evitar que los pines se enciendan y apaguen indefinidamente.
//   while(true) {}
// }
