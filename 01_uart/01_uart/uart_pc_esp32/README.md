# Práctica UART — PC ↔ ESP32

## Objetivo

Comprobar la comunicación serial entre la computadora y el ESP32 mediante el Monitor Serial, enviando comandos de texto para controlar un LED.

## Materiales

- ESP32
- Cable USB
- PC
- Arduino IDE
- LED integrado del ESP32

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
