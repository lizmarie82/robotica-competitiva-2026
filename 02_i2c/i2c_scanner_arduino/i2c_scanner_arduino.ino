// Práctica: Scanner I2C — Arduino UNO / Nano / Mega
// Objetivo: Detectar todos los dispositivos conectados al bus I2C.
//
// Pines I2C:
//   UNO / Nano:  SDA=A4,  SCL=A5
//   Mega:        SDA=20,  SCL=21
//   R4 WiFi:     SDA=A4,  SCL=A5
//
// IMPORTANTE: El Arduino UNO opera a 5V.
// Si conectas sensores de 3.3V, verifica compatibilidad.
// La mayoría de sensores I2C (MPU6050, OLED SSD1306) toleran 5V en SDA/SCL.

#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);  // Esperar al Monitor Serial (necesario en R4 WiFi)

  Serial.println("=== Scanner I2C — Arduino ===");
  Serial.println("UNO/Nano:  SDA=A4, SCL=A5");
  Serial.println("Mega:      SDA=20, SCL=21");
  Serial.println("----------------------------");
}

void loop() {
  int dispositivos = 0;

  for (byte direccion = 1; direccion < 127; direccion++) {
    Wire.beginTransmission(direccion);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Encontrado en 0x");
      if (direccion < 16) Serial.print("0");
      Serial.print(direccion, HEX);
      Serial.print(" -> ");
      Serial.println(identificarDispositivo(direccion));
      dispositivos++;
    }
  }

  if (dispositivos == 0) {
    Serial.println("Sin dispositivos. Verifica conexiones.");
  } else {
    Serial.print("Total: ");
    Serial.print(dispositivos);
    Serial.println(" dispositivo(s).");
  }

  Serial.println("---Escaneando en 5s...");
  delay(5000);
}

String identificarDispositivo(byte dir) {
  switch (dir) {
    case 0x68: return "MPU6050 [AD0=LOW]";
    case 0x69: return "MPU6050 [AD0=HIGH]";
    case 0x48: return "TMP117 [ADD0=GND]";
    case 0x70: return "SHTC3";
    case 0x3C: return "OLED SSD1306";
    case 0x3D: return "OLED SSD1306 [alt]";
    default:   return "Desconocido";
  }
}
