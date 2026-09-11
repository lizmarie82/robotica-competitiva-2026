# Changelog — Robótica Competitiva 2026

Registro cronológico de avances, prácticas completadas y cambios en el repositorio.

---

## [2026-05-18] — Inicio del proyecto y Fase 1

### Agregado

- Estructura inicial de carpetas del repositorio.
- `README.md` principal con descripción del proyecto, hardware y metodología.
- `00_documentacion/roadmap_general.md` — fases 1 a 5 del proyecto.
- `00_documentacion/bitacora_general.md` — bitácora de sesiones de práctica.
- `00_documentacion/metodologia_trabajo.md` — metodología de trabajo por práctica.
- `00_documentacion/mapa_protocolos.md` — comparativa UART / I2C / SPI / PWM.
- `00_documentacion/plan_2_semanas_comunicaciones.md` — plan detallado Fase 1.
- `00_documentacion/conceptos/que_es_uart.md` — concepto técnico UART.
- `00_documentacion/conceptos/que_es_i2c.md` — concepto técnico I2C.
- `00_documentacion/conceptos/que_es_spi.md` — concepto técnico SPI.
- `00_documentacion/conceptos/que_es_pwm.md` — concepto técnico PWM.
- `01_uart/01_uart/uart_pc_esp32/uart_pc_esp32.ino` — sketch UART PC <-> ESP32.
- `01_uart/01_uart/uart_pc_esp32/README.md` — documentación completa de la práctica.
- Imágenes: ESP32, LED encendido, captura del Monitor Serial.
- `.gitignore` configurado para proyectos Arduino/C++.

### Prácticas completadas

- ✅ **UART PC <-> ESP32** — Comunicación serial básica, control de LED por comandos.

---

## [2026-09-10] — Mejoras del repositorio (rama: mejoras/auditoria-2026)

### Agregado

- `LICENSE` — Licencia MIT.
- `CHANGELOG.md` — este archivo.
- `.github/workflows/arduino-build.yml` — CI automático para compilar sketches ESP32.
- `00_documentacion/troubleshooting/errores_comunes.md` — guía de errores comunes.

### Mejorado

- `README.md` — eliminada etiqueta incorrecta de "privado", agregados badges de estado,
  tabla de progreso de fases y enlaces directos a subcarpetas.
- Tabla de carpetas en README ahora tiene links clicables.

---

## Próximas entradas previstas

- `[fecha]` — Práctica UART entre dos placas (ESP32 <-> Arduino).
- `[fecha]` — Práctica I2C con sensor MPU6050.
- `[fecha]` — Práctica I2C con sensor SHTC3 / TMP117.
- `[fecha]` — Práctica PWM con control de LED (fade).
- `[fecha]` — Práctica PWM con servo motor.
- `[fecha]` — Práctica SPI con módulo SD.
- `[fecha]` — Sistema integrado (UART + I2C + PWM).
