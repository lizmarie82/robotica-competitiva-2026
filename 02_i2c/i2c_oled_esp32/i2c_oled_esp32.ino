// Práctica: I2C — Pantalla OLED SSD1306 con ESP32
// Objetivo: Mostrar texto y datos en pantalla OLED 128x64 via I2C.
//
// Librerías requeridas (instalar en Arduino IDE):
//   - Adafruit SSD1306
//   - Adafruit GFX Library
//
// Conexión:
//   OLED VCC  -> ESP32 3.3V
//   OLED GND  -> ESP32 GND
//   OLED SDA  -> ESP32 GPIO21
//   OLED SCL  -> ESP32 GPIO22
//
// Dirección I2C típica: 0x3C (puede ser 0x3D en algunos módulos)

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA  128
#define ALTO_PANTALLA    64
#define OLED_RESET       -1   // -1 = sin pin de reset
#define OLED_ADDR       0x3C

Adafruit_SSD1306 oled(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, OLED_RESET);

unsigned long tiempoInicio;
int contador = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("ERROR: No se encontro la pantalla OLED en 0x3C.");
    Serial.println("Verifica conexiones y dirección I2C.");
    while (true);  // Detener ejecución
  }

  tiempoInicio = millis();

  // Pantalla de bienvenida
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.println("=== ESP32 + OLED ===");
  oled.println("Practica I2C");
  oled.println("");
  oled.println("Iniciando...");
  oled.display();
  delay(2000);

  Serial.println("=== OLED SSD1306 + ESP32 ===");
}

void loop() {
  contador++;
  unsigned long segundos = (millis() - tiempoInicio) / 1000;

  oled.clearDisplay();

  // Título
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.println("ESP32 + OLED I2C");
  oled.drawLine(0, 9, 127, 9, SSD1306_WHITE);

  // Contador y tiempo
  oled.setCursor(0, 14);
  oled.print("Ciclos: ");
  oled.println(contador);

  oled.setCursor(0, 25);
  oled.print("Tiempo: ");
  oled.print(segundos);
  oled.println("s");

  // Texto grande
  oled.setTextSize(2);
  oled.setCursor(0, 42);
  oled.print("Hola!");

  oled.display();

  // También imprimir en Monitor Serial
  Serial.print("Ciclo: "); Serial.print(contador);
  Serial.print(" | Tiempo: "); Serial.print(segundos); Serial.println("s");

  delay(500);
}
