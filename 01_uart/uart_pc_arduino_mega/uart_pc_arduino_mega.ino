// Práctica: UART PC ↔ Arduino Mega 2560
// Plataforma: Arduino Mega 2560
// Objetivo: Recibir comandos desde el Monitor Serial y controlar un LED.
//
// Notas de la plataforma:
//   - El Mega tiene 4 puertos UART: Serial (USB), Serial1, Serial2, Serial3
//   - Serial  → pines 0 (RX) y 1 (TX) → también conectado al USB
//   - Serial1 → pines 19 (RX1) y 18 (TX1)
//   - Serial2 → pines 17 (RX2) y 16 (TX2)
//   - Serial3 → pines 15 (RX3) y 14 (TX3)
//   - LED integrado en pin 13
//   - Opera a 5V lógico

const int LED_PIN = 13;  // LED integrado Arduino Mega
bool ledState = false;

// Puerto usado para comunicacion con la PC (via USB)
#define SERIAL_PC Serial

// Puerto libre para comunicar con otro dispositivo (ej: ESP32)
// #define SERIAL_ESP32 Serial1   // descomentar si se usa

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  SERIAL_PC.begin(9600);
  delay(500);

  SERIAL_PC.println("=== UART PC <-> Arduino Mega ===");
  SERIAL_PC.println("Puertos UART disponibles en el Mega:");
  SERIAL_PC.println("  Serial  (USB)   -> pines 0/1");
  SERIAL_PC.println("  Serial1         -> pines 18/19");
  SERIAL_PC.println("  Serial2         -> pines 16/17");
  SERIAL_PC.println("  Serial3         -> pines 14/15");
  SERIAL_PC.println("--------------------------------");
  SERIAL_PC.println("Comandos: ON | OFF | STATUS");
  SERIAL_PC.println("--------------------------------");
}

void loop() {
  if (SERIAL_PC.available() > 0) {
    String command = SERIAL_PC.readStringUntil('\n');
    command.trim();
    command.toUpperCase();

    if (command == "ON") {
      ledState = true;
      digitalWrite(LED_PIN, HIGH);
      SERIAL_PC.println("LED encendido");
    }
    else if (command == "OFF") {
      ledState = false;
      digitalWrite(LED_PIN, LOW);
      SERIAL_PC.println("LED apagado");
    }
    else if (command == "STATUS") {
      SERIAL_PC.print("Estado del LED: ");
      SERIAL_PC.println(ledState ? "ENCENDIDO" : "APAGADO");
    }
    else {
      SERIAL_PC.print("Comando no reconocido: ");
      SERIAL_PC.println(command);
      SERIAL_PC.println("Usa: ON, OFF o STATUS");
    }
  }
}
