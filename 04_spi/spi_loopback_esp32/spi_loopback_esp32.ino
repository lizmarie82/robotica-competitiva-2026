// Práctica: SPI — Test Loopback con ESP32
// Objetivo: Verificar que el bus SPI funciona correctamente conectando
//           MOSI directamente a MISO (sin dispositivo externo).
//           Si el byte enviado es igual al recibido, el bus funciona.
//
// Pines SPI por defecto en ESP32 (VSPI):
//   MOSI -> GPIO 23
//   MISO -> GPIO 19
//   SCK  -> GPIO 18
//   CS   -> GPIO 5
//
// Conexión para loopback:
//   MOSI (GPIO23) -> MISO (GPIO19)  [cable corto directo]
//   CS puede dejarse sin conectar en este test

#include <SPI.h>

const int CS_PIN = 5;

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);  // CS inactivo

  SPI.begin();  // MOSI=23, MISO=19, SCK=18

  Serial.println("=== SPI Loopback Test — ESP32 ===");
  Serial.println("MOSI=GPIO23 conectado a MISO=GPIO19");
  Serial.println("Enviando y recibiendo bytes...");
  Serial.println("---------------------------------");
}

void loop() {
  byte bytes_prueba[] = {0xAA, 0x55, 0xFF, 0x00, 0x42, 0x13, 0x7F};
  bool todo_ok = true;

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  digitalWrite(CS_PIN, LOW);

  for (byte b : bytes_prueba) {
    byte recibido = SPI.transfer(b);
    bool ok = (b == recibido);
    if (!ok) todo_ok = false;

    Serial.print("  Enviado: 0x"); Serial.print(b, HEX);
    Serial.print("  Recibido: 0x"); Serial.print(recibido, HEX);
    Serial.println(ok ? "  [OK]" : "  [FALLO]");
  }

  digitalWrite(CS_PIN, HIGH);
  SPI.endTransaction();

  Serial.println(todo_ok ? ">>> Bus SPI OK" : ">>> ERROR en el bus SPI");
  Serial.println("---------------------------------");
  delay(2000);
}
