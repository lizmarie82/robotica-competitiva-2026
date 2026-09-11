# Práctica UART — PC ↔ Raspberry Pi Pico W

## Objetivo

Usar el puerto USB del Raspberry Pi Pico W para comunicarse con la PC mediante el REPL de MicroPython (que actúa como UART serial), enviar comandos de texto y controlar el LED integrado.

---

## Plataformas compatibles con este script

| Plataforma | LED | Lenguaje | Notas |
|---|---|---|---|
| Raspberry Pi Pico W | `Pin("LED")` | MicroPython | LED via chip WiFi CYW43439 |
| Raspberry Pi Pico H | `Pin(25)` | MicroPython | LED en GPIO25 directo |
| Raspberry Pi Pico (clasico) | `Pin(25)` | MicroPython | Sin WiFi |

---

## Materiales

- Raspberry Pi Pico W (o Pico H / Pico clasico)
- Cable USB micro
- PC
- Thonny IDE (recomendado) o cualquier terminal serial

---

## Diferencias clave vs ESP32 y Arduino

| Característica | Pico W | ESP32 | Arduino UNO |
|---|---|---|---|
| Lenguaje | MicroPython / C (SDK) | C++ (Arduino) | C++ (Arduino) |
| Voltaje lógico | 3.3V | 3.3V | 5V |
| LED integrado | `Pin("LED")` | `GPIO 2` | `Pin 13` |
| WiFi | Sí (CYW43439) | Sí | No |
| UART hardware | 2 (uart0, uart1) | 3 (UART0/1/2) | 1 (Serial) |
| Baud rate USB | Configurable | 115200 típico | 9600 típico |
| IDE recomendado | Thonny | Arduino IDE | Arduino IDE |

---

## Pines UART hardware del Pico W

| Puerto | TX | RX | Notas |
|---|---|---|---|
| `uart0` | GPIO 0 | GPIO 1 | Por defecto |
| `uart1` | GPIO 4 | GPIO 5 | Alternativo |

> En esta práctica se usa el puerto USB (REPL), **no los pines UART físicos**.

---

## Configuración con Thonny IDE

1. Instalar Thonny: https://thonny.org
2. Conectar Pico W via USB
3. En Thonny: `Herramientas > Opciones > Intérprete > MicroPython (Raspberry Pi Pico)`
4. Copiar el archivo `uart_pc_rpi_pico.py` a la Pico como `main.py`
5. Al reiniciar, el script corre automáticamente
6. Usar la consola de Thonny o cualquier terminal serial como Monitor Serial

---

## Configuración alternativa (terminal serial)

Si se usa un terminal como PuTTY o el Monitor Serial de Arduino IDE:

| Parámetro | Valor |
|---|---|
| Puerto | El COM/ttyACM que aparezca |
| Baud rate | 115200 |
| Final de línea | Newline |

---

## Comandos implementados

| Comando | Acción |
|---|---|
| `ON` | Enciende el LED integrado |
| `OFF` | Apaga el LED integrado |
| `STATUS` | Muestra el estado actual del LED |
| `INFO` | Muestra información de la plataforma y MicroPython |

---

## Resultado esperado

```txt
=== UART PC <-> Raspberry Pi Pico W ===
Comandos disponibles:
  ON     -> Encender LED integrado
  OFF    -> Apagar LED integrado
  STATUS -> Mostrar estado del LED
  INFO   -> Informacion de la plataforma
----------------------------------------
LED encendido
LED apagado
Estado del LED: APAGADO
Plataforma: Raspberry Pi Pico W
MicroPython version: 3.4.0
...
```

---

## Errores comunes

| Error | Causa probable | Solución |
|---|---|---|
| Pico no aparece como COM | MicroPython no instalado | Flashear MicroPython UF2 en la Pico |
| `Pin("LED")` falla | Pico clasico (no W) | Cambiar a `Pin(25, Pin.OUT)` |
| Script no corre al arrancar | Archivo no se llama `main.py` | Guardar como `main.py` en la Pico |
| Terminal muestra >>> (REPL) | Script no se guardó | Guardar el archivo y reiniciar |

---

## Cómo instalar MicroPython en el Pico W

1. Descargar el firmware UF2 desde: https://micropython.org/download/rp2-pico-w/
2. Mantener presionado el botón `BOOTSEL` y conectar el USB
3. Arrastar el archivo `.uf2` a la unidad que aparece (`RPI-RP2`)
4. El Pico reinicia con MicroPython instalado

---

## Estado

⏳ Pendiente de realizar.
