# Plan de 2 semanas — Comunicaciones en sistemas embebidos

## Meta general

Comprender, probar y documentar los protocolos UART, I2C, SPI y PWM mediante prácticas con ESP32, Arduino, Raspberry Pi y sensores reales.

## Protocolos principales

- UART: comunicación serial entre dispositivos.
- I2C: comunicación con sensores mediante SDA y SCL.
- SPI: comunicación rápida con periféricos.
- PWM: control de salidas como LEDs, motores y servos.

## Semana 1

| Día | Tema | Resultado esperado |
|---|---|---|
| Día 1 | Mapa general de comunicaciones | Tabla comparativa de protocolos |
| Día 2 | UART PC ↔ ESP32 | Comandos ON/OFF/STATUS |
| Día 3 | UART entre dos placas | ESP32 y Arduino intercambian mensajes |
| Día 4 | I2C Scanner | Tabla de direcciones I2C |
| Día 5 | TMP117 + SHTC3 | Lectura de temperatura y humedad |
| Día 6 | BMP581 + MPU6050 | Lectura de presión y movimiento |
| Día 7 | Bitácora | Registro de errores y soluciones |

## Semana 2

| Día | Tema | Resultado esperado |
|---|---|---|
| Día 8 | PWM con LED | Control de brillo |
| Día 9 | PWM aplicado a motor o simulación | Comandos SPEED y STOP |
| Día 10 | SPI conceptual | Mapa de pines y casos de uso |
| Día 11 | Raspberry Pi ↔ ESP32 | Comandos por UART |
| Día 12 | Dashboard I2C con OLED | Visualización de datos |
| Día 13 | Sistema integrado | UART + I2C + PWM |
| Día 14 | Evaluación final | Demostración y bitácora completa |

## Criterio de éxito mínimo

Al finalizar estas dos semanas debo lograr:

- Enviar y recibir comandos por UART.
- Detectar sensores I2C con un scanner.
- Leer al menos tres sensores I2C.
- Controlar una salida mediante PWM.
- Comprender el uso general de SPI.
- Integrar UART + I2C + PWM en una práctica simple.

## Evidencias esperadas

- Códigos organizados por carpeta.
- Capturas del monitor serial.
- Fotos de conexiones.
- Tabla de errores y soluciones.
- Reflexión técnica al finalizar cada práctica.
