# ¿Qué es UART?

UART (Universal Asynchronous Receiver-Transmitter) es un protocolo de comunicación serial utilizado para intercambiar datos entre dispositivos electrónicos.

Es uno de los métodos más simples y utilizados en sistemas embebidos y robótica.

---

# ¿Cómo funciona?

UART transmite información bit por bit mediante dos líneas principales:

| Línea | Función |
|---|---|
| TX | Transmisión de datos |
| RX | Recepción de datos |

Para que dos dispositivos se comuniquen:

- TX de un dispositivo debe conectarse a RX del otro.
- RX debe conectarse a TX.
- Ambos dispositivos deben compartir GND.

---

# Características principales

- Comunicación serial.
- Comunicación asíncrona.
- Punto a punto.
- No requiere señal de reloj externa.

---

# Parámetros importantes

## Baud rate

Velocidad de transmisión de datos.

Ejemplos comunes:

- 9600
- 115200

Ambos dispositivos deben usar el mismo baud rate.

---

# Ventajas

- Fácil de implementar.
- Muy útil para depuración.
- Compatible con muchas placas.
- Ideal para comunicación entre microcontroladores.

---

# Limitaciones

- Solo permite comunicación punto a punto.
- Distancias limitadas.
- Menor velocidad que SPI.

---

# Uso en robótica

UART se utiliza frecuentemente para:

- depuración mediante Monitor Serial,
- comunicación entre ESP32 y Raspberry Pi,
- módulos Bluetooth,
- GPS,
- LoRa,
- sensores seriales.

---

# Ejemplo práctico

ESP32 conectado a una computadora mediante USB-Serial:

```txt
PC ↔ USB ↔ ESP32
```

---

# Errores comunes

| Error | Posible causa |
|---|---|
| No hay comunicación | TX/RX invertidos |
| Datos extraños | Baud rate incorrecto |
| Comunicación inestable | No compartir GND |

---

# Relación con otros protocolos

| Protocolo | Diferencia principal |
|---|---|
| UART | Punto a punto |
| I2C | Bus compartido |
| SPI | Mayor velocidad |
