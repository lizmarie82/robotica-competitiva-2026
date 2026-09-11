// Práctica: I2C — Pantalla OLED SSD1306 con Arduino UNO / Mega
// Objetivo: Mostrar texto y datos en pantalla OLED 128x64 via I2C.
//
// Librerías requeridas: Adafruit SSD1306 + Adafruit GFX Library
//
// Conexión Arduino UNO / Nano:
//   OLED VCC -> 3.3V o 5V (SSD1306 acepta ambos)
//   OLED GND -> GND
//   OLED SDA -> A4
//   OLED SCL -> A5
//
// Conexión Arduino Mega:
//   OLED SDA -> Pin 20
//   OLED SCL -> Pin 21
//
// NOTA: Arduino UNO tiene poca RAM (2KB). Usar display de 128x32 si hay problemas.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO 128
#define ALTO   64   // Cambiar a 32 si usas pantalla de 128x32
#define OLED_RESET  -1
#define OLED_ADDR  0x3C

Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);

int contador = 0;

void setup() {
  Serial.begin(9600);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("ERROR: OLED no encontrada");
    while (true);
  }

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.println("Arduino + OLED I2C");
  oled.println("Practica lista!");
  oled.display();
  delay(2000);
}

void loop() {
  contador++;

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(0, 0);
  oled.println("Arduino + OLED");
  oled.drawLine(0, 9, 127, 9, SSD1306_WHITE);

  oled.setCursor(0, 14);
  oled.print("Ciclos: ");
  oled.println(contador);

  oled.setTextSize(2);
  oled.setCursor(20, 38);
  oled.println("Hola!");

  oled.display();

  Serial.print("Ciclo: "); Serial.println(contador);
  delay(500);
}
