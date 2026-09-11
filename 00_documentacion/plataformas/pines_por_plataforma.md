# Referencia de pines por plataforma

Guía rápida de pines importantes para cada microcontrolador disponible en el proyecto.

---

## UART — Pines de comunicación serial

| Plataforma | TX | RX | Puerto | Voltaje | Baud rate típico |
|---|---|---|---|---|---|
| ESP32 | GPIO1 (TX0) | GPIO3 (RX0) | Serial (USB via CP2102) | 3.3V | 115200 |
| ESP32 (UART1) | GPIO17 | GPIO16 | Serial1 | 3.3V | 115200 |
| ESP32 (UART2) | GPIO17 | GPIO16 | Serial2 | 3.3V | 115200 |
| Arduino UNO | 1 (TX) | 0 (RX) | Serial (USB) | 5V | 9600 |
| Arduino Nano | 1 (TX) | 0 (RX) | Serial (USB) | 5V | 9600 |
| Arduino Mega | 1 / 18 / 16 / 14 | 0 / 19 / 17 / 15 | Serial / Serial1 / Serial2 / Serial3 | 5V | 9600 |
| Arduino R4 WiFi | 1 (TX) | 0 (RX) | Serial (USB) | 3.3V | 115200 |
| Raspberry Pi Pico W | GPIO0 | GPIO1 | uart0 | 3.3V | 115200 |
| Raspberry Pi Pico W | GPIO4 | GPIO5 | uart1 | 3.3V | 115200 |

---

## I2C — Pines de bus de datos

| Plataforma | SDA | SCL | Puerto | Voltaje |
|---|---|---|---|---|
| ESP32 | GPIO21 | GPIO22 | Wire (por defecto) | 3.3V |
| Arduino UNO | A4 | A5 | Wire | 5V |
| Arduino Nano | A4 | A5 | Wire | 5V |
| Arduino Mega | 20 (SDA) | 21 (SCL) | Wire | 5V |
| Arduino R4 WiFi | A4 / SDA | A5 / SCL | Wire | 3.3V |
| Raspberry Pi Pico W | GPIO4 | GPIO5 | I2C0 | 3.3V |
| Raspberry Pi Pico W | GPIO2 | GPIO3 | I2C1 (alt) | 3.3V |

---

## SPI — Pines de comunicación rápida

| Plataforma | MOSI | MISO | SCK | CS | Voltaje |
|---|---|---|---|---|---|
| ESP32 | GPIO23 | GPIO19 | GPIO18 | GPIO5 | 3.3V |
| Arduino UNO | 11 | 12 | 13 | 10 | 5V |
| Arduino Nano | 11 | 12 | 13 | 10 | 5V |
| Arduino Mega | 51 | 50 | 52 | 53 | 5V |
| Arduino R4 WiFi | 11 | 12 | 13 | 10 | 3.3V |
| Raspberry Pi Pico W | GPIO19 | GPIO16 | GPIO18 | GPIO17 | 3.3V |

---

## PWM — Pines con soporte de modulación

| Plataforma | Pines PWM | Frecuencia | Resolución | API |
|---|---|---|---|---|
| ESP32 | Cualquier GPIO (16 canales LEDC) | Configurable | 1–16 bits | `ledcSetup()` / `ledcWrite()` |
| Arduino UNO | 3, 5, 6, 9, 10, 11 | 490 Hz / 980 Hz | 8 bits | `analogWrite()` |
| Arduino Nano | 3, 5, 6, 9, 10, 11 | 490 Hz / 980 Hz | 8 bits | `analogWrite()` |
| Arduino Mega | 2-13, 44-46 | 490 Hz / 980 Hz | 8 bits | `analogWrite()` |
| Arduino R4 WiFi | 3, 5, 6, 9, 10, 11 | Configurable | 12 bits | `analogWrite()` |
| Raspberry Pi Pico W | Cualquier GPIO (16 canales) | Configurable | 16 bits | MicroPython `PWM()` |

---

## LED integrado por plataforma

| Plataforma | Pin LED integrado | Notas |
|---|---|---|
| ESP32 | GPIO2 | Activo en HIGH |
| Arduino UNO | Pin 13 | Activo en HIGH |
| Arduino Nano | Pin 13 | Activo en HIGH |
| Arduino Mega | Pin 13 | Activo en HIGH |
| Arduino R4 WiFi | Pin 13 | Activo en HIGH |
| Raspberry Pi Pico W | `Pin("LED")` | Via chip WiFi CYW43439 |
| Raspberry Pi Pico H | GPIO25 | Activo en HIGH |

---

## Voltajes lógicos — Compatibilidad entre plataformas

> ⚠️ Conectar directamente 5V a un pin de 3.3V puede dañar el microcontrolador.

| Plataforma | Voltaje lógico | Compatible directo con 5V |
|---|---|---|
| ESP32 | 3.3V | ❌ No |
| Arduino UNO | 5V | ✅ Si |
| Arduino Nano | 5V | ✅ Si |
| Arduino Mega | 5V | ✅ Si |
| Arduino R4 WiFi | 3.3V | ❌ No |
| Raspberry Pi Pico W | 3.3V | ❌ No |

Si necesitas conectar Arduino UNO (5V) con ESP32 o Pico (3.3V):
- Usar divisor de voltaje resistivo (resistencias 10K + 20K)
- Usar módulo level shifter bidireccional (recomendado)

---

## Memoria y capacidad

| Plataforma | Flash | RAM | Velocidad CPU | Núcleos |
|---|---|---|---|---|
| ESP32 | 4 MB | 520 KB | 240 MHz | 2 (Xtensa LX6) |
| Arduino UNO | 32 KB | 2 KB | 16 MHz | 1 (AVR) |
| Arduino Nano | 32 KB | 2 KB | 16 MHz | 1 (AVR) |
| Arduino Mega | 256 KB | 8 KB | 16 MHz | 1 (AVR) |
| Arduino R4 WiFi | 256 KB | 32 KB | 48 MHz | 1 (Renesas RA4M1) |
| Raspberry Pi Pico W | 2 MB | 264 KB | 133 MHz | 2 (RP2040) |
