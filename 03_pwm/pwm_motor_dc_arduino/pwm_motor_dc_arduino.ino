// Práctica: PWM — Control Motor DC con L298N + Arduino UNO / Mega
// Objetivo: Controlar velocidad y dirección de motor DC con driver L298N.
//
// Conexión L298N -> Arduino UNO:
//   ENA  -> Pin 9  (PWM — debe ser pin PWM)
//   IN1  -> Pin 7
//   IN2  -> Pin 8
//   GND  -> GND común
//
// En Arduino Mega usar pines PWM: 2-13, 44-46

const int ENA = 9;   // PWM
const int IN1 = 7;
const int IN2 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  detenerMotor();

  Serial.println("=== Motor DC + L298N + Arduino ===");
  Serial.println("Comandos: F<vel>, B<vel>, S  (vel=0-255)");
}

void adelante(int velocidad) {
  velocidad = constrain(velocidad, 0, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidad);
  Serial.print("Adelante | vel="); Serial.println(velocidad);
}

void atras(int velocidad) {
  velocidad = constrain(velocidad, 0, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velocidad);
  Serial.print("Atras | vel="); Serial.println(velocidad);
}

void detenerMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  Serial.println("Motor detenido");
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    cmd.toUpperCase();

    if (cmd.startsWith("F")) adelante(cmd.substring(1).toInt());
    else if (cmd.startsWith("B")) atras(cmd.substring(1).toInt());
    else if (cmd == "S") detenerMotor();
    else Serial.println("Usa F<vel>, B<vel> o S");
  }
}
