# Práctica UART — PC ↔ Arduino Mega 2560

## Objetivo

Explorar los múltiples puertos UART del Arduino Mega 2560 y usar el puerto Serial (USB) para recibir comandos desde el Monitor Serial y controlar un LED.

---

## Por qué el Mega es especial para UART

El Arduino Mega 2560 es la plataforma con **más puertos UART físicos** de la familia Arduino:

| Puerto | Pines físicos | Uso típico |
|---|---|---|
| `Serial` | USB (pines 0 / 1) | Comunicación con PC |
| `Serial1` | 19 (RX1) / 18 (TX1) | Comunicación con ESP32, GPS, Bluetooth |
| `Serial2` | 17 (RX2) / 16 (TX2) | Segundo dispositivo externo |
| `Serial3` | 15 (RX3) / 14 (TX3) | Tercer dispositivo externo |

Esto lo hace ideal como **hub de comunicaciones** en un robot que necesita hablar con varios dispositivos al mismo tiempo.

---

## Materiales

- Arduino Mega 2560
- Cable USB tipo B
- PC
- Arduino IDE

---

## Configuración en Arduino IDE

```txt
Herramientas > Placa > Arduino AVR Boards > Arduino Mega or Mega 2560
Herramientas > Procesador > ATmega2560 (Mega 2560)
```

---

## Configuración de comunicación

| Parámetro | Valor |
|---|---|
| Baud rate | 9600 |
| Final de línea | Newline |
| Puerto | El que aparezca disponible |

---

## Comandos implementados

| Comando | Acción |
|---|---|
| `ON` | Enciende el LED (pin 13) |
| `OFF` | Apaga el LED |
| `STATUS` | Muestra el estado actual del LED |

---

## Ventaja del Mega en robótica competitiva

En un robot que usa múltiples periféricos simultáneamente:

```txt
Mega Serial  ← Monitor Serial / depuración desde PC
Mega Serial1 → ESP32 (comunicación WiFi/BT)
Mega Serial2 → Módulo GPS
Mega Serial3 → Módulo LoRa o Bluetooth HC-05
```

Cada `Serial` es completamente independiente — sin conflictos de pines.

---

## Errores comunes

| Error | Causa probable | Solución |
|---|---|---|
| LED no enciende | Pin 13 distinto al usado | Verificar que se usa pin 13 |
| Serial1 no funciona | Pines 0/1 conectados a algo externo | Liberar pines 0/1 si se usa USB |
| No compila | Procesador incorrecto | Seleccionar ATmega2560 |

---

## Estado

⏳ Pendiente de realizar.
