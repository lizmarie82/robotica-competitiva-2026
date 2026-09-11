// Práctica: PWM — Control Motor DC con L298N + ESP32
// Objetivo: Controlar velocidad y dirección de un motor DC usando el driver L298N.
//
// El L298N es un driver de puente H que permite:
//   - Controlar la VELOCIDAD con PWM (pin ENA o ENB)
//   - Controlar la DIRECCIÓN con dos pines de lógica (IN1/IN2 o IN3/IN4)
//
// Conexión L298N -> ESP32:
//   ENA  -> GPIO 14  (PWM de velocidad)
//   IN1  -> GPIO 26  (dirección)
//   IN2  -> GPIO 27  (dirección)
//   GND  -> GND común
//   5V   -> fuente externa 5V
//   12V  -> fuente del motor (6V-12V según el motor)
//
// IMPORTANTE: GND del ESP32, L298N y fuente externa deben estar todos conectados.

const int ENA  = 14;   // PWM velocidad
const int IN1  = 26;   // Dirección 1
const int IN2  = 27;   // Dirección 2

const int CANAL_PWM  = 2;
const int FRECUENCIA = 1000;  // 1kHz para motores DC
const int RESOLUCION = 8;     // 0-255

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);
  ledcAttachPin(ENA, CANAL_PWM);

  detenerMotor();

  Serial.println("=== Motor DC + L298N + ESP32 ===");
  Serial.println("Comandos en Monitor Serial:");
  Serial.println("  F<vel>  -> Adelante, vel=0-255  (ej: F200)");
  Serial.println("  B<vel>  -> Atras,    vel=0-255  (ej: B150)");
  Serial.println("  S       -> Detener");
}

void adelante(int velocidad) {
  velocidad = constrain(velocidad, 0, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  ledcWrite(CANAL_PWM, velocidad);
  Serial.print("Adelante | vel="); Serial.println(velocidad);
}

void atras(int velocidad) {
  velocidad = constrain(velocidad, 0, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  ledcWrite(CANAL_PWM, velocidad);
  Serial.print("Atras    | vel="); Serial.println(velocidad);
}

void detenerMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  ledcWrite(CANAL_PWM, 0);
  Serial.println("Motor detenido");
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    cmd.toUpperCase();

    if (cmd.startsWith("F")) {
      int vel = cmd.substring(1).toInt();
      adelante(vel);
    } else if (cmd.startsWith("B")) {
      int vel = cmd.substring(1).toInt();
      atras(vel);
    } else if (cmd == "S") {
      detenerMotor();
    } else {
      Serial.println("Comando invalido. Usa F<vel>, B<vel> o S");
    }
  }
}
