# Práctica: PWM — LED Fade con Raspberry Pi Pico W
# Objetivo: Controlar brillo de LED con PWM en MicroPython.
#
# El Pico W tiene PWM en casi todos sus GPIO (16 canales).
# Resolución: 16 bits (0 a 65535)
# Frecuencia: configurable
#
# Conexión:
#   LED anodo (+) -> Resistencia 220 Ohm -> GPIO 15
#   LED catodo (-) -> GND

from machine import Pin, PWM
import time

LED_PIN   = 15       # GPIO con PWM
FRECUENCIA = 5000    # Hz

pwm = PWM(Pin(LED_PIN))
pwm.freq(FRECUENCIA)

print("=== PWM LED Fade — Raspberry Pi Pico W ===")
print(f"Pin: GPIO{LED_PIN} | Frecuencia: {FRECUENCIA}Hz | Resolucion: 16 bits")

brillo    = 0
incremento = 1000    # Paso sobre 0-65535

while True:
    pwm.duty_u16(brillo)

    porcentaje = int(brillo / 65535 * 100)
    print(f"Brillo: {brillo}/65535 ({porcentaje}%)")

    brillo += incremento
    if brillo <= 0 or brillo >= 65535:
        incremento = -incremento
        brillo = max(0, min(65535, brillo))

    time.sleep(0.02)
