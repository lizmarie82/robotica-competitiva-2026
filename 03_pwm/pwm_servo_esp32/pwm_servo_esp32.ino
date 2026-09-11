// Práctica: PWM — Control de Servo con ESP32
// Objetivo: Mover un servo motor entre posiciones usando PWM con LEDC.
//
// Servos estándar: 50Hz, pulso entre 500us y 2400us
//   0°   ->  ~500us  (duty mínimo)
//   90°  -> ~1450us  (duty centro)
//   180° -> ~2400us  (duty máximo)
//
// Conexión:
//   Servo ROJO   (VCC) -> 5V externo (NO usar el 3.3V del ESP32)
//   Servo NEGRO  (GND) -> GND compartido con ESP32
//   Servo AMARILLO/BLANCO (señal) -> GPIO 13
//
// IMPORTANTE: Alimentar el servo con fuente externa de 5V.
// El ESP32 no puede suministrar la corriente necesaria.

const int SERVO_PIN   = 13;
const int CANAL_PWM   = 1;
const int FRECUENCIA  = 50;     // 50Hz para servos estándar
const int RESOLUCION  = 16;     // 16 bits para mayor precisión

// Convertir grados (0-180) a duty cycle para 16 bits a 50Hz
// Período = 20ms | 1 tick = 20ms/65535 ≈ 0.305us
int gradosToDuty(int grados) {
  // Mapear 0-180° a 500us-2400us
  int pulso_us = map(grados, 0, 180, 500, 2400);
  // Convertir us a duty (ticks de 16 bits)
  return (int)(pulso_us / 20000.0 * 65535);
}

void setup() {
  Serial.begin(115200);

  ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);
  ledcAttachPin(SERVO_PIN, CANAL_PWM);

  Serial.println("=== Servo PWM — ESP32 ===");
  Serial.println("Pin: GPIO13 | Canal: 1 | 50Hz | 16 bits");
  Serial.println("Comandos: escribe el angulo (0-180) en Monitor Serial");
  Serial.println("O el servo barrera automaticamente.");
}

void moverAGrados(int grados) {
  grados = constrain(grados, 0, 180);
  ledcWrite(CANAL_PWM, gradosToDuty(grados));
  Serial.print("Servo -> "); Serial.print(grados); Serial.println("°");
  delay(500);
}

void loop() {
  // Leer comandos del Monitor Serial
  if (Serial.available() > 0) {
    int angulo = Serial.parseInt();
    if (angulo >= 0 && angulo <= 180) {
      moverAGrados(angulo);
    }
  } else {
    // Barrido automático si no hay entrada
    for (int pos = 0; pos <= 180; pos += 10) {
      moverAGrados(pos);
      delay(100);
    }
    for (int pos = 180; pos >= 0; pos -= 10) {
      moverAGrados(pos);
      delay(100);
    }
  }
}
