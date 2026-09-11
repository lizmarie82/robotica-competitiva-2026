// Práctica: I2C — Lectura MPU6050 con ESP32
// Objetivo: Leer acelerómetro y giroscopio del MPU6050 via I2C.
//
// Librería requerida: MPU6050 by Electronic Cats (instalar en Arduino IDE)
// Alternativa: Wire directo (incluido en este sketch como fallback)
//
// Conexión:
//   MPU6050 VCC  -> ESP32 3.3V
//   MPU6050 GND  -> ESP32 GND
//   MPU6050 SDA  -> ESP32 GPIO21
//   MPU6050 SCL  -> ESP32 GPIO22
//   MPU6050 AD0  -> GND   (dirección 0x68)
//
// Dirección I2C:
//   AD0=GND  -> 0x68
//   AD0=VCC  -> 0x69

#include <Wire.h>

const int MPU_ADDR = 0x68;

// Registros del MPU6050
const int REG_PWR_MGMT_1  = 0x6B;
const int REG_ACCEL_XOUT  = 0x3B;
const int REG_GYRO_XOUT   = 0x43;
const int REG_TEMP_OUT     = 0x41;

// Variables para los datos crudos
int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t temp_raw;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  // SDA=GPIO21, SCL=GPIO22

  // Despertar el MPU6050 (por defecto está en modo sleep)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(REG_PWR_MGMT_1);
  Wire.write(0x00);  // 0 = despertar
  Wire.endTransmission();

  delay(100);

  Serial.println("=== MPU6050 + ESP32 ===");
  Serial.println("Acelerometro (g) | Giroscopio (deg/s) | Temperatura (C)");
  Serial.println("----------------------------------------------------------");
}

void leerMPU6050() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(REG_ACCEL_XOUT);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);

  ax       = (Wire.read() << 8) | Wire.read();
  ay       = (Wire.read() << 8) | Wire.read();
  az       = (Wire.read() << 8) | Wire.read();
  temp_raw = (Wire.read() << 8) | Wire.read();
  gx       = (Wire.read() << 8) | Wire.read();
  gy       = (Wire.read() << 8) | Wire.read();
  gz       = (Wire.read() << 8) | Wire.read();
}

void loop() {
  leerMPU6050();

  // Convertir valores crudos
  float accel_x = ax / 16384.0;  // ±2g por defecto -> 16384 LSB/g
  float accel_y = ay / 16384.0;
  float accel_z = az / 16384.0;

  float gyro_x  = gx / 131.0;   // ±250 deg/s por defecto -> 131 LSB/deg/s
  float gyro_y  = gy / 131.0;
  float gyro_z  = gz / 131.0;

  float temp_c  = (temp_raw / 340.0) + 36.53;

  // Mostrar en Monitor Serial
  Serial.print("Accel (g):  X="); Serial.print(accel_x, 3);
  Serial.print("  Y="); Serial.print(accel_y, 3);
  Serial.print("  Z="); Serial.print(accel_z, 3);

  Serial.print("  |  Gyro (dps):  X="); Serial.print(gyro_x, 1);
  Serial.print("  Y="); Serial.print(gyro_y, 1);
  Serial.print("  Z="); Serial.print(gyro_z, 1);

  Serial.print("  |  Temp: "); Serial.print(temp_c, 1); Serial.println(" C");

  delay(200);
}
