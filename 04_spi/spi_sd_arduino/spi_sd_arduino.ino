// Práctica: SPI — Tarjeta SD con Arduino UNO / Mega
// Objetivo: Leer y escribir archivos en tarjeta SD via SPI.
//
// Librería: SD (incluida en Arduino IDE)
//
// Conexión Arduino UNO:
//   SD CS   -> Pin 10
//   SD MOSI -> Pin 11
//   SD MISO -> Pin 12
//   SD SCK  -> Pin 13
//   SD VCC  -> 5V (o 3.3V si el módulo tiene regulador)
//   SD GND  -> GND
//
// Arduino Mega:
//   SD CS   -> Pin 53
//   SD MOSI -> Pin 51
//   SD MISO -> Pin 50
//   SD SCK  -> Pin 52

#include <SPI.h>
#include <SD.h>

const int SD_CS = 10;   // Mega: cambiar a 53

void setup() {
  Serial.begin(9600);

  Serial.println("=== SD Card SPI — Arduino ===");

  if (!SD.begin(SD_CS)) {
    Serial.println("ERROR: SD no encontrada. Verifica cableado y formato FAT32.");
    while (true);
  }

  Serial.println("SD inicializada.");

  // Escribir archivo
  File archivo = SD.open("test.txt", FILE_WRITE);
  if (archivo) {
    archivo.println("Hola desde Arduino!");
    archivo.println("SPI + SD funcionando.");
    archivo.close();
    Serial.println("Archivo test.txt escrito.");
  }

  // Leer archivo
  archivo = SD.open("test.txt");
  if (archivo) {
    Serial.println("--- test.txt ---");
    while (archivo.available()) Serial.write(archivo.read());
    archivo.close();
    Serial.println("---");
  }
}

void loop() {
  // Sin loop activo — todo en setup()
  delay(10000);
}
