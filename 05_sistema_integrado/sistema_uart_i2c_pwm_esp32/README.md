# Práctica Sistema Integrado — UART + I2C + PWM (ESP32)
Integra los tres protocolos: recibe comandos por UART, lee temperatura del MPU6050 (I2C) y controla motor/LED (PWM).
Incluye modo automático: la velocidad del motor varía según la temperatura del sensor.
**Comandos:** STATUS | MOTOR F<vel> | MOTOR B<vel> | MOTOR S | LED <val> | AUTO ON/OFF | **Estado:** ⏳ Pendiente
