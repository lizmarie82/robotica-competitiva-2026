// Práctica: SPI — Test Loopback con Arduino UNO / Mega
// Objetivo: Verificar el bus SPI conectando MOSI a MISO.
//
// Pines SPI Arduino UNO / Nano:
//   MOSI -> Pin 11
//   MISO -> Pin 12
//   SCK  -> Pin 13
//   CS   -> Pin 10
//
// Pines SPI Arduino Mega:
//   MOSI -> Pin 51
//   MISO -> Pin 50
//   SCK  -> Pin 52
//   CS   -> Pin 53
//
// Conexión loopback: MOSI -> MISO (cable directo)

#include <SPI.h>

const int CS_PIN = 10;  // Mega: usar pin 53

void setup() {
  Serial.begin(9600);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);
  SPI.begin();

  Serial.println("=== SPI Loopback — Arduino ===");
  Serial.println("UNO/Nano: MOSI(11) -> MISO(12)");
  Serial.println("Mega:     MOSI(51) -> MISO(50)");
}

void loop() {
  byte prueba[] = {0xAA, 0x55, 0xFF, 0x00, 0x42};
  bool todo_ok = true;

  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  digitalWrite(CS_PIN, LOW);

  for (byte b : prueba) {
    byte recibido = SPI.transfer(b);
    bool ok = (b == recibido);
    if (!ok) todo_ok = false;
    Serial.print("Env=0x"); Serial.print(b, HEX);
    Serial.print(" Rec=0x"); Serial.print(recibido, HEX);
    Serial.println(ok ? " [OK]" : " [FALLO]");
  }

  digitalWrite(CS_PIN, HIGH);
  SPI.endTransaction();

  Serial.println(todo_ok ? "SPI OK" : "SPI ERROR");
  delay(2000);
}
