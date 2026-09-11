// Práctica: PWM — LED Fade con ESP32
// Objetivo: Controlar el brillo de un LED usando PWM con la API LEDC del ESP32.
//
// El ESP32 NO tiene analogWrite() nativo como Arduino.
// Usa la API LEDC (LED Control) con 16 canales independientes.
//
// Conexión:
//   LED anodo (+) -> Resistencia 220 Ohm -> GPIO 5
//   LED catodo (-) -> GND
//
// También funciona con el LED integrado en GPIO2 (sin resistencia)

const int LED_PIN    = 5;     // Pin del LED externo (o usar 2 para el integrado)
const int CANAL_PWM  = 0;     // Canal LEDC (0-15)
const int FRECUENCIA = 5000;  // Frecuencia PWM en Hz
const int RESOLUCION = 8;     // Resolución en bits (8 bits = 0 a 255)

int brillo    = 0;
int incremento = 5;

void setup() {
  Serial.begin(115200);

  // Configurar canal PWM
  ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);

  // Asociar el canal al pin físico
  ledcAttachPin(LED_PIN, CANAL_PWM);

  Serial.println("=== PWM LED Fade — ESP32 ===");
  Serial.println("Canal: 0 | Frecuencia: 5000Hz | Resolucion: 8 bits");
  Serial.println("LED en GPIO5 (o GPIO2 para el integrado)");
}

void loop() {
  // Aplicar brillo al LED
  ledcWrite(CANAL_PWM, brillo);

  Serial.print("Brillo: "); Serial.print(brillo);
  Serial.print("/255 (");
  Serial.print(map(brillo, 0, 255, 0, 100));
  Serial.println("%)");

  // Oscilación entre 0 y 255
  brillo += incremento;
  if (brillo <= 0 || brillo >= 255) {
    incremento = -incremento;
    brillo = constrain(brillo, 0, 255);
  }

  delay(20);
}
