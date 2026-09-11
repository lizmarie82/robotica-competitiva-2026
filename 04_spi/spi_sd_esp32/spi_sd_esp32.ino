// Práctica: SPI — Tarjeta SD con ESP32
// Objetivo: Leer y escribir archivos en una tarjeta microSD usando SPI.
//
// Librería requerida: SD (incluida en Arduino IDE)
//
// Conexión módulo SD -> ESP32:
//   SD CS   -> GPIO 5
//   SD MOSI -> GPIO 23
//   SD MISO -> GPIO 19
//   SD SCK  -> GPIO 18
//   SD VCC  -> 3.3V o 5V (según el módulo)
//   SD GND  -> GND
//
// Usar tarjeta SD formateada en FAT32.
// Tamaño recomendado: hasta 32 GB.

#include <SPI.h>
#include <SD.h>

const int SD_CS = 5;

const char* ARCHIVO_LOG  = "/bitacora.txt";
const char* ARCHIVO_TEST = "/test.txt";

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=== SD Card SPI — ESP32 ===");

  // Inicializar SD
  if (!SD.begin(SD_CS)) {
    Serial.println("ERROR: No se pudo inicializar la SD.");
    Serial.println("Verifica: tarjeta insertada, FAT32, cableado correcto.");
    while (true);
  }

  Serial.println("Tarjeta SD inicializada correctamente.");

  // Mostrar información de la SD
  uint8_t tipo = SD.cardType();
  Serial.print("Tipo de tarjeta: ");
  if      (tipo == CARD_MMC)  Serial.println("MMC");
  else if (tipo == CARD_SD)   Serial.println("SDSC");
  else if (tipo == CARD_SDHC) Serial.println("SDHC");
  else                        Serial.println("Desconocido");

  uint64_t tamano = SD.cardSize() / (1024 * 1024);
  Serial.print("Tamaño: "); Serial.print(tamano); Serial.println(" MB");

  // Escribir archivo de prueba
  escribirArchivo(ARCHIVO_TEST, "Hola desde ESP32!\nSPI + SD funciona.");

  // Leer el archivo
  leerArchivo(ARCHIVO_TEST);

  // Agregar entrada a la bitácora
  agregarLinea(ARCHIVO_LOG, "Sesion iniciada — ESP32 + SD OK");

  Serial.println("\nSD lista. Escribe 'L' para leer la bitacora.");
}

void escribirArchivo(const char* ruta, const char* contenido) {
  File archivo = SD.open(ruta, FILE_WRITE);
  if (archivo) {
    archivo.println(contenido);
    archivo.close();
    Serial.print("Archivo escrito: "); Serial.println(ruta);
  } else {
    Serial.print("ERROR al escribir: "); Serial.println(ruta);
  }
}

void leerArchivo(const char* ruta) {
  File archivo = SD.open(ruta);
  if (archivo) {
    Serial.print("\n--- Contenido de "); Serial.print(ruta); Serial.println(" ---");
    while (archivo.available()) {
      Serial.write(archivo.read());
    }
    archivo.close();
    Serial.println("---");
  } else {
    Serial.print("ERROR al leer: "); Serial.println(ruta);
  }
}

void agregarLinea(const char* ruta, const char* linea) {
  File archivo = SD.open(ruta, FILE_APPEND);
  if (archivo) {
    archivo.println(linea);
    archivo.close();
    Serial.print("Linea agregada a: "); Serial.println(ruta);
  }
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    if (cmd == 'L' || cmd == 'l') {
      leerArchivo(ARCHIVO_LOG);
    } else if (cmd == 'W' || cmd == 'w') {
      agregarLinea(ARCHIVO_LOG, "Entrada manual del usuario");
      Serial.println("Linea agregada.");
    }
  }
}
