# ¿Qué es SPI?

SPI (Serial Peripheral Interface) es un protocolo de comunicación serial de alta velocidad utilizado en sistemas embebidos.

Es muy utilizado cuando se requiere transmitir datos rápidamente.

---

# ¿Cómo funciona?

SPI utiliza varias líneas:

| Línea | Función |
|---|---|
| MOSI | Datos del maestro al esclavo |
| MISO | Datos del esclavo al maestro |
| SCK | Señal de reloj |
| CS/SS | Selección de dispositivo |

---

# Características principales

- Comunicación serial síncrona.
- Alta velocidad.
- Requiere más cables.

---

# Ventajas

- Muy rápido.
- Comunicación estable.
- Excelente para transferencia de datos.

---

# Limitaciones

- Usa más pines.
- Cableado más complejo.

---

# Uso en robótica

SPI se utiliza frecuentemente en:

- pantallas,
- tarjetas SD,
- sensores rápidos,
- módulos RF,
- comunicación de alto rendimiento.

---

# Ejemplo práctico

ESP32 conectado a una pantalla SPI:

```txt
ESP32 ↔ Display SPI
```

---

# Errores comunes

| Error | Posible causa |
|---|---|
| No responde dispositivo | CS incorrecto |
| Datos corruptos | Clock mal configurado |
| Comunicación inestable | Cableado largo |

---

# Relación con otros protocolos

| Protocolo | Diferencia principal |
|---|---|
| UART | Más simple |
| I2C | Menos cables |
| SPI | Mayor velocidad |
