// Práctica: PWM — Control de Servo con Arduino UNO / Mega
// Objetivo: Mover un servo motor usando la librería Servo.h
//
// La librería Servo.h maneja automáticamente el PWM a 50Hz.
// No necesitas calcular el duty cycle manualmente.
//
// Conexión:
//   Servo ROJO   -> 5V (puede usar el 5V del Arduino para servos pequeños)
//   Servo NEGRO  -> GND
//   Servo AMARILLO/BLANCO -> Pin 9
//
// Pines disponibles para Servo en UNO: 9, 10
// En Mega: casi cualquier pin digital

#include <Servo.h>

Servo miServo;
const int SERVO_PIN = 9;

void setup() {
  Serial.begin(9600);
  miServo.attach(SERVO_PIN);
  miServo.write(90);  // Posición inicial: centro

  Serial.println("=== Servo PWM — Arduino ===");
  Serial.println("Pin: 9 | Libreria: Servo.h");
  Serial.println("Escribe un angulo (0-180) en el Monitor Serial");
}

void loop() {
  if (Serial.available() > 0) {
    int angulo = Serial.parseInt();
    angulo = constrain(angulo, 0, 180);
    miServo.write(angulo);
    Serial.print("Servo -> "); Serial.print(angulo); Serial.println("°");
    delay(300);
  } else {
    // Barrido automático
    for (int pos = 0; pos <= 180; pos += 5) {
      miServo.write(pos);
      Serial.print("-> "); Serial.print(pos); Serial.println("°");
      delay(80);
    }
    for (int pos = 180; pos >= 0; pos -= 5) {
      miServo.write(pos);
      Serial.print("-> "); Serial.print(pos); Serial.println("°");
      delay(80);
    }
  }
}
