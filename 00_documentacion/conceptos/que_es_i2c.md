# ¿Qué es I2C?

I2C (Inter-Integrated Circuit) es un protocolo de comunicación serial diseñado para conectar múltiples dispositivos usando pocas líneas.

Es ampliamente utilizado en sensores y sistemas embebidos.

---

# ¿Cómo funciona?

I2C utiliza dos líneas principales:

| Línea | Función |
|---|---|
| SDA | Datos |
| SCL | Reloj |

Todos los dispositivos comparten estas líneas.

Cada dispositivo tiene una dirección única.

---

# Características principales

- Comunicación serial.
- Bus compartido.
- Permite múltiples dispositivos.
- Usa direccionamiento.

---

# Ventajas

- Requiere pocos cables.
- Permite conectar muchos sensores.
- Muy utilizado en robótica.

---

# Limitaciones

- Menor velocidad que SPI.
- Más sensible al ruido.
- Direcciones pueden entrar en conflicto.

---

# Uso en robótica

I2C se usa frecuentemente en:

- IMUs,
- sensores ambientales,
- OLEDs,
- expanders,
- RTCs.

---

# Ejemplo práctico

ESP32 conectado a varios sensores:

```txt
ESP32
 ├── MPU6050
 ├── BMP581
 └── OLED
```

Todos usando SDA y SCL compartidos.

---

# Pines comunes en ESP32

| Función | GPIO común |
|---|---|
| SDA | GPIO 21 |
| SCL | GPIO 22 |

---

# Errores comunes

| Error | Posible causa |
|---|---|
| Sensor no detectado | Dirección incorrecta |
| Bus congelado | Cableado incorrecto |
| Lecturas erróneas | Ruido eléctrico |

---

# Relación con otros protocolos

| Protocolo | Diferencia principal |
|---|---|
| UART | Punto a punto |
| I2C | Bus compartido |
| SPI | Mayor velocidad y más cables |
