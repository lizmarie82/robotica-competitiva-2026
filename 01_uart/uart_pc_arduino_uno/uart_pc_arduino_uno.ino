// Práctica: UART PC ↔ Arduino UNO / Nano
// Plataforma: Arduino UNO, Arduino Nano, Arduino R4 WiFi
// Objetivo: Recibir comandos desde el Monitor Serial y controlar un LED.
//
// Notas de la plataforma:
//   - LED integrado en pin 13 (UNO/Nano) o pin 13 (R4 WiFi)
//   - Opera a 5V (UNO/Mega) o 3.3V (R4 WiFi)
//   - Puerto USB-Serial integrado (no necesita chip externo)

const int LED_PIN = 13;  // LED integrado en Arduino UNO / Nano / R4
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);   // UNO funciona mejor con 9600; también acepta 115200
  delay(500);

  Serial.println("=== UART PC <-> Arduino UNO ===");
  Serial.println("Comandos disponibles:");
  Serial.println("  ON     -> Encender LED (pin 13)");
  Serial.println("  OFF    -> Apagar LED");
  Serial.println("  STATUS -> Mostrar estado del LED");
  Serial.println("-------------------------------");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toUpperCase();

    if (command == "ON") {
      ledState = true;
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED encendido");
    }
    else if (command == "OFF") {
      ledState = false;
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED apagado");
    }
    else if (command == "STATUS") {
      Serial.print("Estado del LED: ");
      Serial.println(ledState ? "ENCENDIDO" : "APAGADO");
    }
    else {
      Serial.print("Comando no reconocido: ");
      Serial.println(command);
      Serial.println("Usa: ON, OFF o STATUS");
    }
  }
}
