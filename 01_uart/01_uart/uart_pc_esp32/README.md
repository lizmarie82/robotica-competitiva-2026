# Práctica UART — PC ↔ ESP32

## Objetivo

Comprobar la comunicación serial entre la computadora y el ESP32 mediante el Monitor Serial, enviando comandos de texto para controlar un LED.

## Materiales
## Hardware utilizado

| Componente | Modelo / detalle |
|---|---|
| Microcontrolador | ESP32 DevKit compatible |
| Módulo principal | ZY-ESP32 WiFi+BT |
| Chip USB-Serial | Silicon Labs CP2102 |
| Regulador de voltaje | AMS1117-3.3 |
| Puerto usado | COM5 |
| Pin del LED utilizado | GPIO 2 |
| Comunicación | USB-Serial / UART |
| Baud rate | 115200 |
| Software | Arduino IDE |
## Placa utilizada

![ESP32 utilizado](../../imagenes/esp32_zy_devkit_cp2102.jpeg)

La placa utilizada es una ESP32 DevKit compatible con módulo ZY-ESP32 WiFi+BT, chip USB-Serial CP2102 y regulador AMS1117-3.3. Fue seleccionada en Arduino IDE como **ESP32 Dev Module**.

## Protocolo utilizado

UART mediante conexión USB-Serial.

## Comandos implementados

| Comando | Acción |
|---|---|
| `ON` | Enciende el LED |
| `OFF` | Apaga el LED |
| `STATUS` | Muestra el estado actual del LED |

## Configuración

- Baud rate: `115200`
- Pin LED: `GPIO 2`

## Resultado esperado

El ESP32 recibe comandos desde el Monitor Serial y responde con mensajes de confirmación.

## Evidencia

Agregar captura del Monitor Serial mostrando los comandos:

- `ON`
- `STATUS`
- `OFF`

## Errores encontrados

| Error | Posible causa | Solución |
|---|---|---|
| No aparece texto en el monitor serial | Baud rate incorrecto | Usar `115200` |
| El LED no enciende | Pin incorrecto | Probar otro pin o LED externo |
| No reconoce comandos | Salto de línea mal configurado | Usar `Newline` o `Both NL & CR` |

## Conclusión técnica

La comunicación UART permite enviar y recibir datos entre el ESP32 y la computadora. Es útil para depuración, control manual y pruebas iniciales de sistemas robóticos.
