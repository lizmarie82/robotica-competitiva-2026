// Práctica: PWM — LED Fade con Arduino UNO / Nano / Mega
// Objetivo: Controlar el brillo de un LED con analogWrite().
//
// Pines PWM en Arduino UNO / Nano: 3, 5, 6, 9, 10, 11
// Pines PWM en Arduino Mega:       2-13, 44-46
//
// Conexión:
//   LED anodo (+) -> Resistencia 220 Ohm -> Pin 9
//   LED catodo (-) -> GND

const int LED_PIN = 9;  // Pin PWM

int brillo    = 0;
int incremento = 5;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("=== PWM LED Fade — Arduino ===");
  Serial.println("Pin PWM: 9 | Resolucion: 8 bits (0-255)");
}

void loop() {
  analogWrite(LED_PIN, brillo);

  Serial.print("Brillo: "); Serial.print(brillo);
  Serial.print("/255 ("); Serial.print(map(brillo, 0, 255, 0, 100)); Serial.println("%)");

  brillo += incremento;
  if (brillo <= 0 || brillo >= 255) {
    incremento = -incremento;
    brillo = constrain(brillo, 0, 255);
  }

  delay(20);
}
