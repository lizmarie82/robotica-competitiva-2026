// Práctica: Scanner I2C — ESP32
// Objetivo: Detectar todos los dispositivos conectados al bus I2C y mostrar sus direcciones.
//
// Pines I2C por defecto en ESP32:
//   SDA -> GPIO 21
//   SCL -> GPIO 22
//
// Conexión de sensores comunes:
//   MPU6050: VCC=3.3V, GND=GND, SDA=GPIO21, SCL=GPIO22
//   TMP117:  VCC=3.3V, GND=GND, SDA=GPIO21, SCL=GPIO22
//   SHTC3:   VCC=3.3V, GND=GND, SDA=GPIO21, SCL=GPIO22
//   OLED:    VCC=3.3V, GND=GND, SDA=GPIO21, SCL=GPIO22

#include <Wire.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(21, 22);  // SDA=GPIO21, SCL=GPIO22

  Serial.println("=== Scanner I2C — ESP32 ===");
  Serial.println("Buscando dispositivos en el bus I2C...");
  Serial.println("Pines: SDA=GPIO21, SCL=GPIO22");
  Serial.println("-----------------------------------");
}

void loop() {
  int dispositivos = 0;

  for (byte direccion = 1; direccion < 127; direccion++) {
    Wire.beginTransmission(direccion);
    byte error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo encontrado en direccion 0x");
      if (direccion < 16) Serial.print("0");
      Serial.print(direccion, HEX);
      Serial.print("  (decimal: ");
      Serial.print(direccion);
      Serial.print(")  -> ");
      Serial.println(identificarDispositivo(direccion));
      dispositivos++;
    }
  }

  if (dispositivos == 0) {
    Serial.println("No se encontraron dispositivos I2C.");
    Serial.println("Verifica conexiones y resistencias pull-up.");
  } else {
    Serial.print("Total: ");
    Serial.print(dispositivos);
    Serial.println(" dispositivo(s) encontrado(s).");
  }

  Serial.println("-----------------------------------");
  Serial.println("Escaneando de nuevo en 5 segundos...");
  delay(5000);
}

// Identifica dispositivos comunes por su dirección I2C
String identificarDispositivo(byte dir) {
  switch (dir) {
    case 0x68: return "MPU6050 (giroscopio/acelerometro) [AD0=LOW]";
    case 0x69: return "MPU6050 (giroscopio/acelerometro) [AD0=HIGH]";
    case 0x48: return "TMP117 (temperatura) [ADD0=GND]";
    case 0x49: return "TMP117 (temperatura) [ADD0=VCC]";
    case 0x70: return "SHTC3 (temperatura y humedad)";
    case 0x47: return "BMP581 (presion) [SDO=GND]";
    case 0x46: return "BMP581 (presion) [SDO=VCC]";
    case 0x3C: return "OLED SSD1306 128x64 [SA0=LOW]";
    case 0x3D: return "OLED SSD1306 128x64 [SA0=HIGH]";
    case 0x57: return "AT24C32 EEPROM (modulo RTC DS3231)";
    case 0x68: return "DS3231 RTC";
    default:   return "Dispositivo desconocido";
  }
}
