// Práctica: Sistema Integrado — UART + I2C + PWM — ESP32
// Objetivo: Demostrar la integración de tres protocolos en un mismo sistema.
//
// Funcionalidades:
//   1. UART  — Recibir comandos desde Monitor Serial
//   2. I2C   — Leer temperatura del MPU6050 (o sin sensor: leer voltaje interno)
//   3. PWM   — Controlar velocidad de un motor DC o brillo de un LED
//
// Conexiones:
//   MPU6050 SDA  -> GPIO 21
//   MPU6050 SCL  -> GPIO 22
//   MPU6050 VCC  -> 3.3V
//   MPU6050 GND  -> GND
//   LED/Motor ENA -> GPIO 14 (PWM)
//   L298N IN1    -> GPIO 26
//   L298N IN2    -> GPIO 27
//
// Comandos UART disponibles:
//   STATUS         — Muestra todos los valores actuales
//   MOTOR F<vel>   — Motor adelante (vel 0-255)
//   MOTOR B<vel>   — Motor atrás
//   MOTOR S        — Motor parar
//   LED <brillo>   — Brillo del LED (0-255)
//   AUTO ON/OFF    — Activa/desactiva modo automático (velocidad según temperatura)

#include <Wire.h>

// --- Pines ---
const int MPU_ADDR   = 0x68;
const int ENA_PIN    = 14;   // PWM motor o LED
const int IN1_PIN    = 26;
const int IN2_PIN    = 27;
const int LEDC_CANAL = 0;

// --- Estado del sistema ---
float temperatura    = 0;
float accel_z        = 0;
int   velocidad_pwm  = 0;
bool  modo_auto      = false;
String direccion_motor = "PARADO";

// --- Inicialización MPU6050 ---
void iniciarMPU6050() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);  // Despertar
  Wire.endTransmission();
  delay(100);
}

// --- Leer temperatura del MPU6050 ---
float leerTemperatura() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x41);  // REG TEMP_OUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2, true);
  int16_t raw = (Wire.read() << 8) | Wire.read();
  return (raw / 340.0) + 36.53;
}

// --- Leer aceleración Z ---
float leerAccelZ() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3F);  // REG ACCEL_ZOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2, true);
  int16_t raw = (Wire.read() << 8) | Wire.read();
  return raw / 16384.0;
}

// --- Control motor ---
void motorAdelante(int vel) {
  vel = constrain(vel, 0, 255);
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  ledcWrite(LEDC_CANAL, vel);
  velocidad_pwm = vel;
  direccion_motor = "ADELANTE";
}

void motorAtras(int vel) {
  vel = constrain(vel, 0, 255);
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  ledcWrite(LEDC_CANAL, vel);
  velocidad_pwm = vel;
  direccion_motor = "ATRAS";
}

void motorParar() {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  ledcWrite(LEDC_CANAL, 0);
  velocidad_pwm = 0;
  direccion_motor = "PARADO";
}

// --- Mostrar estado completo ---
void mostrarStatus() {
  Serial.println("==========================================");
  Serial.println("        ESTADO DEL SISTEMA ESP32         ");
  Serial.println("==========================================");
  Serial.print("  Temperatura (MPU6050): "); Serial.print(temperatura, 1); Serial.println(" C");
  Serial.print("  Aceleracion Z:         "); Serial.print(accel_z, 3); Serial.println(" g");
  Serial.print("  Motor:                 "); Serial.println(direccion_motor);
  Serial.print("  Velocidad PWM:         "); Serial.print(velocidad_pwm); Serial.println("/255");
  Serial.print("  Modo automatico:       "); Serial.println(modo_auto ? "ON" : "OFF");
  Serial.println("==========================================");
}

// --- Procesar comandos UART ---
void procesarComando(String cmd) {
  cmd.trim();
  cmd.toUpperCase();

  if (cmd == "STATUS") {
    mostrarStatus();
  }
  else if (cmd.startsWith("MOTOR F")) {
    int vel = cmd.substring(7).toInt();
    motorAdelante(vel);
    Serial.print("Motor adelante | vel="); Serial.println(vel);
  }
  else if (cmd.startsWith("MOTOR B")) {
    int vel = cmd.substring(7).toInt();
    motorAtras(vel);
    Serial.print("Motor atras | vel="); Serial.println(vel);
  }
  else if (cmd == "MOTOR S") {
    motorParar();
    Serial.println("Motor detenido");
  }
  else if (cmd.startsWith("LED ")) {
    int brillo = cmd.substring(4).toInt();
    brillo = constrain(brillo, 0, 255);
    ledcWrite(LEDC_CANAL, brillo);
    velocidad_pwm = brillo;
    Serial.print("LED brillo="); Serial.println(brillo);
  }
  else if (cmd == "AUTO ON") {
    modo_auto = true;
    Serial.println("Modo automatico ACTIVADO (velocidad segun temperatura)");
  }
  else if (cmd == "AUTO OFF") {
    modo_auto = false;
    motorParar();
    Serial.println("Modo automatico DESACTIVADO");
  }
  else {
    Serial.println("Comandos: STATUS | MOTOR F<vel> | MOTOR B<vel> | MOTOR S | LED <val> | AUTO ON/OFF");
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  ledcSetup(LEDC_CANAL, 1000, 8);
  ledcAttachPin(ENA_PIN, LEDC_CANAL);

  iniciarMPU6050();
  motorParar();

  Serial.println("==========================================");
  Serial.println("  Sistema Integrado UART + I2C + PWM     ");
  Serial.println("  Plataforma: ESP32                      ");
  Serial.println("==========================================");
  Serial.println("Escribe STATUS para ver el estado actual.");
  Serial.println("Escribe MOTOR F200 para mover el motor.");
}

void loop() {
  // Leer sensores I2C
  temperatura = leerTemperatura();
  accel_z     = leerAccelZ();

  // Modo automático: velocidad proporcional a la temperatura
  if (modo_auto) {
    // Mapear temperatura (25-40°C) a velocidad (50-200)
    int vel_auto = (int)map(constrain((int)temperatura, 25, 40), 25, 40, 50, 200);
    motorAdelante(vel_auto);
  }

  // Leer comandos UART
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    procesarComando(cmd);
  }

  delay(100);
}
