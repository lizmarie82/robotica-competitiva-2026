# ¿Qué es PWM?

PWM (Pulse Width Modulation) es una técnica utilizada para controlar potencia o señales digitales mediante pulsos.

Se utiliza ampliamente para controlar:

- LEDs,
- motores,
- servomotores,
- velocidad,
- brillo.

---

# ¿Cómo funciona?

PWM alterna rápidamente entre:

- HIGH
- LOW

La relación entre tiempo encendido y apagado se llama:

# Duty Cycle

---

# Duty Cycle

| Duty Cycle | Resultado |
|---|---|
| 0% | Siempre apagado |
| 50% | Mitad de potencia |
| 100% | Siempre encendido |

---

# Características principales

- Señal digital.
- Simula comportamiento analógico.
- Muy utilizada en control.

---

# Ventajas

- Bajo consumo.
- Fácil implementación.
- Excelente para motores y LEDs.

---

# Limitaciones

- Puede generar ruido eléctrico.
- Algunos motores requieren drivers.

---

# Uso en robótica

PWM se utiliza para:

- control de motores DC,
- control de velocidad,
- servomotores,
- iluminación,
- ventiladores.

---

# Ejemplo práctico

Control de brillo de un LED:

```txt
Mayor duty cycle = mayor brillo
```

---

# Errores comunes

| Error | Posible causa |
|---|---|
| Motor no responde | PWM en pin incorrecto |
| Ruido en motores | Fuente insuficiente |
| Vibración | Frecuencia incorrecta |

---

# Relación con otros protocolos

PWM no es un protocolo de comunicación como UART o I2C.

PWM es una técnica de control de señales.
