# Práctica: Scanner I2C — Raspberry Pi Pico W
# Lenguaje: MicroPython
# Objetivo: Detectar todos los dispositivos en el bus I2C.
#
# Pines I2C en el Pico W:
#   I2C0: SDA=GPIO4,  SCL=GPIO5  (por defecto en este script)
#   I2C1: SDA=GPIO2,  SCL=GPIO3  (alternativo)
#
# Conectar sensores a 3.3V (VBUS o 3V3 del Pico)
# Agregar resistencias pull-up de 4.7 kOhm en SDA y SCL si la comunicacion es inestable

from machine import I2C, Pin
import time

# Diccionario de dispositivos conocidos
DISPOSITIVOS_CONOCIDOS = {
    0x68: "MPU6050 giroscopio/acelerometro [AD0=LOW]",
    0x69: "MPU6050 giroscopio/acelerometro [AD0=HIGH]",
    0x48: "TMP117 sensor de temperatura [ADD0=GND]",
    0x49: "TMP117 sensor de temperatura [ADD0=VCC]",
    0x70: "SHTC3 temperatura y humedad",
    0x47: "BMP581 presion barometrica [SDO=GND]",
    0x46: "BMP581 presion barometrica [SDO=VCC]",
    0x3C: "OLED SSD1306 128x64 [SA0=LOW]",
    0x3D: "OLED SSD1306 128x64 [SA0=HIGH]",
}

def identificar(addr):
    return DISPOSITIVOS_CONOCIDOS.get(addr, "Dispositivo desconocido")

def escanear_i2c(i2c, nombre_bus):
    print(f"\n=== Scanner I2C — {nombre_bus} ===")
    dispositivos = i2c.scan()

    if not dispositivos:
        print("  No se encontraron dispositivos.")
        print("  Verifica conexiones, voltaje y resistencias pull-up.")
    else:
        print(f"  {len(dispositivos)} dispositivo(s) encontrado(s):")
        for addr in dispositivos:
            print(f"    0x{addr:02X} (dec: {addr:3d})  ->  {identificar(addr)}")
    return dispositivos

# Configurar I2C0: SDA=GPIO4, SCL=GPIO5
i2c0 = I2C(0, sda=Pin(4), scl=Pin(5), freq=400_000)

print("Raspberry Pi Pico W — Scanner I2C")
print("I2C0: SDA=GPIO4, SCL=GPIO5 | freq=400kHz")
print("------------------------------------------")

while True:
    escanear_i2c(i2c0, "I2C0 (GPIO4/GPIO5)")
    print("\nEscaneando de nuevo en 5 segundos...")
    time.sleep(5)
