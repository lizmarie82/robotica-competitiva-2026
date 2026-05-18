// Práctica: UART PC ↔ ESP32
// Objetivo: Recibir comandos desde el Monitor Serial y controlar un LED.

const int LED_PIN = 2;   // LED integrado en muchos ESP32
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  delay(1000);

  Serial.println("=== UART PC ↔ ESP32 ===");
  Serial.println("Comandos disponibles:");
  Serial.println("ON     -> Encender LED");
  Serial.println("OFF    -> Apagar LED");
  Serial.println("STATUS -> Mostrar estado");
  Serial.println("------------------------");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();        // elimina espacios y saltos de línea
    command.toUpperCase(); // convierte a mayúsculas

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
