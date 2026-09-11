// Práctica: Sistema Integrado — UART + I2C + PWM — Arduino Mega 2560
// Objetivo: Integrar los tres protocolos en el Arduino Mega.
//
// El Mega es ideal para este sistema porque tiene 4 UART hardware:
//   Serial  (USB)  — depuración y comandos desde PC
//   Serial1        — comunicación con ESP32 u otro módulo
//   Serial2        — expansión futura (GPS, LoRa)
//   Serial3        — expansión futura
//
// Conexiones:
//   MPU6050 SDA -> Pin 20 (SDA)
//   MPU6050 SCL -> Pin 21 (SCL)
//   MPU6050 VCC -> 5V (el MPU6050 acepta 5V)
//   MPU6050 GND -> GND
//   Motor ENA   -> Pin 9 (PWM)
//   Motor IN1   -> Pin 7
//   Motor IN2   -> Pin 8
//
// Comandos UART (Monitor Serial):
//   STATUS             — Estado completo
//   MOTOR F<vel>       — Adelante (vel 0-255)
//   MOTOR B<vel>       — Atrás
//   MOTOR S            — Parar
//   REENVIAR <mensaje> — Retransmitir mensaje por Serial1 hacia otro dispositivo

#include <Wire.h>

// --- Pines motor ---
const int ENA  = 9;
const int IN1  = 7;
const int IN2  = 8;

// --- MPU6050 ---
const int MPU_ADDR = 0x68;

// --- Estado ---
int   vel_motor = 0;
String dir_motor = "PARADO";
float temperatura = 0;

void iniciarMPU() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(100);
}

float leerTemperatura() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x41);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2, true);
  int16_t raw = (Wire.read() << 8) | Wire.read();
  return (raw / 340.0) + 36.53;
}

void motorAdelante(int vel) {
  vel = constrain(vel, 0, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, vel);
  vel_motor = vel;
  dir_motor = "ADELANTE";
}

void motorAtras(int vel) {
  vel = constrain(vel, 0, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, vel);
  vel_motor = vel;
  dir_motor = "ATRAS";
}

void motorParar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  vel_motor = 0;
  dir_motor = "PARADO";
}

void mostrarStatus() {
  temperatura = leerTemperatura();
  Serial.println("=== ESTADO — Arduino Mega ===");
  Serial.print("  Temperatura:   "); Serial.print(temperatura, 1); Serial.println(" C");
  Serial.print("  Motor:         "); Serial.println(dir_motor);
  Serial.print("  Velocidad PWM: "); Serial.print(vel_motor); Serial.println("/255");
  Serial.println("  Serial1 activo para comunicacion externa");
  Serial.println("==============================");
}

void procesarComando(String cmd) {
  cmd.trim();
  cmd.toUpperCase();

  if (cmd == "STATUS") mostrarStatus();
  else if (cmd.startsWith("MOTOR F")) { motorAdelante(cmd.substring(7).toInt()); Serial.println("Motor Adelante"); }
  else if (cmd.startsWith("MOTOR B")) { motorAtras(cmd.substring(7).toInt());    Serial.println("Motor Atras"); }
  else if (cmd == "MOTOR S")           { motorParar(); Serial.println("Motor Parado"); }
  else if (cmd.startsWith("REENVIAR ")) {
    // Retransmitir por Serial1 (hacia ESP32 u otro módulo)
    String msg = cmd.substring(9);
    Serial1.println(msg);
    Serial.print("Reenviado por Serial1: "); Serial.println(msg);
  }
  else {
    Serial.println("Comandos: STATUS | MOTOR F<vel> | MOTOR B<vel> | MOTOR S | REENVIAR <msg>");
  }
}

void setup() {
  Serial.begin(9600);    // PC
  Serial1.begin(9600);   // Dispositivo externo (ESP32, módulo BT, etc.)

  Wire.begin();

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  motorParar();

  iniciarMPU();

  Serial.println("=== Sistema Integrado — Arduino Mega ===");
  Serial.println("UART + I2C (MPU6050) + PWM (Motor DC)");
  Serial.println("Escribe STATUS para comenzar.");
}

void loop() {
  // Leer comandos del Monitor Serial (PC)
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    procesarComando(cmd);
  }

  // Leer mensajes de Serial1 (dispositivo externo) y mostrar en Serial
  if (Serial1.available() > 0) {
    String msg = Serial1.readStringUntil('\n');
    Serial.print("[Serial1 recibido]: "); Serial.println(msg);
  }

  delay(50);
}
