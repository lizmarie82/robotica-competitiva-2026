# Guía de troubleshooting — Robótica Competitiva 2026

Registro de errores comunes encontrados durante las prácticas, con sus causas y soluciones.

---

## UART

| Error observado | Posible causa | Solución aplicada |
|---|---|---|
| No aparece texto en el Monitor Serial | Baud rate incorrecto | Configurar en 115200 en el Monitor Serial y en Serial.begin() |
| Texto ilegible / caracteres extraños | Baud rate distinto entre IDE y sketch | Usar el mismo valor en ambos lados |
| El LED no responde al comando | Final de línea incorrecto | Usar 'Newline' en el Monitor Serial |
| Puerto COM no aparece en Arduino IDE | Driver CP2102 no instalado | Instalar drivers Silicon Labs CP2102 |
| Comando no reconocido aunque escrito bien | Espacios o caracteres invisibles | Usar command.trim() y command.toUpperCase() en el sketch |
| ESP32 no sube el sketch | Puerto COM ocupado o incorrecto | Cerrar Monitor Serial antes de subir; seleccionar el COM correcto |

---

## I2C

| Error observado | Posible causa | Solución aplicada |
|---|---|---|
| El sensor no aparece en el scanner I2C | Dirección incorrecta o sin VCC | Verificar alimentación y dirección hexadecimal |
| Datos incorrectos leídos | SDA y SCL invertidos | Verificar pines: en ESP32 SDA=GPIO21, SCL=GPIO22 |
| Comunicación inestable | Cables largos o sin pull-up | Usar resistencias pull-up (4.7 kOhm) en SDA y SCL |
| Varios sensores no responden | Dirección I2C repetida | Verificar que cada sensor tenga dirección única |

---

## SPI

| Error observado | Posible causa | Solución aplicada |
|---|---|---|
| Sin respuesta del dispositivo SPI | CS no configurado | Verificar que el pin CS esté en LOW antes de transmitir |
| Datos corruptos | Velocidad SPI demasiado alta | Reducir frecuencia SPI |
| Interferencia entre dispositivos | Bus SPI compartido mal gestionado | Asegurar que solo un CS esté activo a la vez |

---

## PWM

| Error observado | Posible causa | Solución aplicada |
|---|---|---|
| El LED no cambia de intensidad | Canal PWM no asignado | Usar ledcSetup() y ledcAttachPin() en ESP32 |
| El servo no responde | Frecuencia PWM incorrecta | Los servos requieren 50 Hz; usar ledcSetup(canal, 50, 16) |
| El motor vibra en lugar de girar suave | Duty cycle fuera de rango | Verificar rango del servo (1000-2000 us) |

---

## ESP32 — General

| Error observado | Posible causa | Solución aplicada |
|---|---|---|
| No se detecta la placa en Arduino IDE | Soporte ESP32 no instalado | Instalar 'esp32 by Espressif Systems' en Gestor de tarjetas |
| Error al subir: 'Failed to connect' | GPIO0 no en modo BOOT | Mantener presionado el botón BOOT al subir |
| GPIO quemado | Señal de 5V conectada directamente | El ESP32 opera a 3.3V; usar divisor de voltaje o level shifter |
| Reinicio aleatorio del ESP32 | Watchdog timer activado | Agregar delay() o yield() en loops intensivos |

---

## Notas generales

- Siempre verificar la alimentación (VCC / GND) antes de buscar errores de código.
- El Monitor Serial debe estar cerrado antes de subir un nuevo sketch.
- Usar GND comun entre todos los dispositivos conectados al mismo bus.
