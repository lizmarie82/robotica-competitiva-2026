// Práctica: I2C — Lectura MPU6050 con Arduino UNO / Mega
// Objetivo: Leer acelerómetro y giroscopio del MPU6050 via I2C.
//
// Conexión Arduino UNO / Nano:
//   MPU6050 VCC  -> 3.3V (o 5V — el MPU6050 acepta ambos)
//   MPU6050 GND  -> GND
//   MPU6050 SDA  -> A4
//   MPU6050 SCL  -> A5
//   MPU6050 AD0  -> GND  (dirección 0x68)
//
// Conexión Arduino Mega:
//   MPU6050 SDA  -> Pin 20
//   MPU6050 SCL  -> Pin 21

#include <Wire.h>

const int MPU_ADDR = 0x68;

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t temp_raw;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Despertar el MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);  // Registro PWR_MGMT_1
  Wire.write(0x00);  // 0 = despertar
  Wire.endTransmission();

  delay(100);

  Serial.println("=== MPU6050 + Arduino ===");
  Serial.println("Ax\tAy\tAz\tGx\tGy\tGz\tTemp(C)");
}

void leerMPU() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);  // Registro ACCEL_XOUT_H
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
  leerMPU();

  float accel_x = ax / 16384.0;
  float accel_y = ay / 16384.0;
  float accel_z = az / 16384.0;
  float gyro_x  = gx / 131.0;
  float gyro_y  = gy / 131.0;
  float gyro_z  = gz / 131.0;
  float temp_c  = (temp_raw / 340.0) + 36.53;

  Serial.print(accel_x, 2); Serial.print("\t");
  Serial.print(accel_y, 2); Serial.print("\t");
  Serial.print(accel_z, 2); Serial.print("\t");
  Serial.print(gyro_x, 1);  Serial.print("\t");
  Serial.print(gyro_y, 1);  Serial.print("\t");
  Serial.print(gyro_z, 1);  Serial.print("\t");
  Serial.println(temp_c, 1);

  delay(200);
}
