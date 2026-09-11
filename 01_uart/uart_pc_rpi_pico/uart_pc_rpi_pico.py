# Práctica: UART PC ↔ Raspberry Pi Pico W
# Plataforma: Raspberry Pi Pico W / Pico H
# Lenguaje: MicroPython
# Objetivo: Recibir comandos desde el Monitor Serial y controlar el LED integrado.
#
# Notas de la plataforma:
#   - Pico W tiene LED integrado accesible como Pin("LED") o Pin(25)
#   - El Pico tiene 2 UARTs hardware: uart0 y uart1
#   - Por USB usa el REPL de MicroPython (no necesita UART físico para Monitor Serial)
#   - Voltaje lógico: 3.3V
#   - Chip RP2040 (Pico) o RP2040 + CYW43439 WiFi (Pico W)

import sys
from machine import Pin
import time

# LED integrado del Pico W
# Pico W:  Pin("LED")  — controlado via chip WiFi CYW43439
# Pico H:  Pin(25)     — GPIO directo
try:
    led = Pin("LED", Pin.OUT)   # Funciona en Pico W
except TypeError:
    led = Pin(25, Pin.OUT)      # Fallback para Pico H / Pico clasico

led.off()
led_state = False

# Mensajes de bienvenida al arrancar
print("=== UART PC <-> Raspberry Pi Pico W ===")
print("Comandos disponibles:")
print("  ON     -> Encender LED integrado")
print("  OFF    -> Apagar LED integrado")
print("  STATUS -> Mostrar estado del LED")
print("  INFO   -> Informacion de la plataforma")
print("----------------------------------------")

def handle_command(command):
    global led_state
    command = command.strip().upper()

    if command == "ON":
        led_state = True
        led.on()
        print("LED encendido")

    elif command == "OFF":
        led_state = False
        led.off()
        print("LED apagado")

    elif command == "STATUS":
        estado = "ENCENDIDO" if led_state else "APAGADO"
        print("Estado del LED: " + estado)

    elif command == "INFO":
        import sys
        print("Plataforma: Raspberry Pi Pico W")
        print("MicroPython version: " + sys.version)
        print("LED pin: Pin('LED')")
        print("Voltaje logico: 3.3V")
        print("UART0: GPIO0 (TX) / GPIO1 (RX)")
        print("UART1: GPIO4 (TX) / GPIO5 (RX)")

    elif command == "":
        pass  # ignorar líneas vacías

    else:
        print("Comando no reconocido: " + command)
        print("Usa: ON, OFF, STATUS o INFO")

# Bucle principal: leer desde USB Serial (stdin)
while True:
    try:
        line = sys.stdin.readline()
        if line:
            handle_command(line)
    except KeyboardInterrupt:
        led.off()
        print("Programa detenido.")
        break
