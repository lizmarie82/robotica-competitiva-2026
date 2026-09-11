# Práctica UART — PC ↔ Arduino UNO / Nano / R4 WiFi

## Objetivo

Comprobar la comunicación serial entre la computadora y un Arduino mediante el Monitor Serial, enviando comandos de texto para controlar el LED integrado (pin 13).

---

## Plataformas compatibles con este sketch

| Plataforma | LED pin | Voltaje | Baud rate recomendado | Notas |
|---|---|---|---|---|
| Arduino UNO | 13 | 5V | 9600 | USB-Serial integrado (ATmega16U2) |
| Arduino Nano | 13 | 5V | 9600 | Chip USB-Serial CH340 o FT232 |
| Arduino Mega | 13 | 5V | 9600 | Puerto Serial0 (pines 0/1) |
| Arduino R4 WiFi | 13 | 3.3V | 9600 / 115200 | Chip USB-Serial integrado |

---

## Materiales

- Arduino UNO (o compatible de la tabla)
- Cable USB
- PC
- Arduino IDE

---

## Diferencias clave vs ESP32

| Característica | Arduino UNO | ESP32 |
|---|---|---|
| LED integrado | Pin 13 | GPIO 2 |
| Voltaje lógico | 5V | 3.3V |
| Chip USB-Serial | ATmega16U2 (integrado) | CP2102 (externo) |
| Baud rate típico | 9600 | 115200 |
| Necesita drivers | No (la mayoría) | Sí (CP2102) |
| WiFi / BT | No (en UNO) | Sí |

---

## Configuración en Arduino IDE

Seleccionar la placa correcta según el modelo:

```txt
Arduino UNO   → Herramientas > Placa > Arduino AVR Boards > Arduino Uno
Arduino Nano  → Herramientas > Placa > Arduino AVR Boards > Arduino Nano
Arduino Mega  → Herramientas > Placa > Arduino AVR Boards > Arduino Mega or Mega 2560
Arduino R4    → Herramientas > Placa > Arduino UNO R4 Boards > Arduino UNO R4 WiFi
```

---

## Configuración de comunicación

| Parámetro | Valor |
|---|---|
| Baud rate | 9600 |
| Final de línea | Newline |
| Puerto | El que aparezca en Herramientas > Puerto |

---

## Comandos implementados

| Comando | Acción |
|---|---|
| `ON` | Enciende el LED (pin 13) |
| `OFF` | Apaga el LED |
| `STATUS` | Muestra el estado actual del LED |

---

## Resultado esperado

```txt
=== UART PC <-> Arduino UNO ===
Comandos disponibles:
  ON     -> Encender LED (pin 13)
  OFF    -> Apagar LED
  STATUS -> Mostrar estado del LED
-------------------------------
LED encendido
LED apagado
Estado del LED: APAGADO
```

---

## Errores comunes

| Error | Causa probable | Solución |
|---|---|---|
| Puerto no aparece | Driver no instalado (Nano CH340) | Instalar driver CH340 |
| No compila | Placa incorrecta en IDE | Seleccionar la placa exacta |
| Texto extraño | Baud rate incorrecto | Usar 9600 en el Monitor Serial |
| LED no enciende | Pin distinto | Verificar pin 13 en tu modelo |

---

## Nota técnica

El Arduino UNO opera a **5V lógico**. Si conectas sensores o módulos de 3.3V (como un ESP32), debes usar un divisor de voltaje o level shifter en las líneas de datos para no dañar los componentes de 3.3V.

---

## Estado

⏳ Pendiente de realizar.
