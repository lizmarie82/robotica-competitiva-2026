# Robótica Competitiva 2026

Este repositorio documenta mi proceso de aprendizaje técnico en robótica competitiva, sistemas embebidos, comunicaciones, sensores, control y desarrollo de robots autónomos.

El objetivo es construir una base sólida en electrónica, programación embebida, integración de hardware y arquitectura de sistemas robóticos mediante prácticas documentadas, pruebas reales y desarrollo progresivo de habilidades técnicas.

---

## Objetivo general

Desarrollar habilidades prácticas en:

- UART
- I2C
- SPI
- PWM
- sensores
- control de motores
- arquitectura de software para robots
- integración de sistemas robóticos
- depuración y documentación técnica

---

# Fase 1 — Comunicaciones en sistemas embebidos

**Período:** Mayo 2026

La primera fase del proyecto está enfocada en comprender y aplicar los principales protocolos de comunicación utilizados en sistemas embebidos y robótica.

Durante esta etapa se trabajará principalmente con ESP32, Arduino y Raspberry Pi para desarrollar fundamentos técnicos en comunicación entre dispositivos, lectura de sensores y control de salidas.

## Temas principales de esta fase

- UART
- I2C
- SPI
- PWM
- Monitor Serial
- comunicación entre microcontroladores
- integración básica de sensores
- control de LEDs y motores
- documentación técnica de prácticas

## Objetivos de aprendizaje de la fase

Al finalizar esta fase se espera poder:

- comunicar dispositivos mediante UART,
- detectar y utilizar sensores I2C,
- comprender la estructura básica de SPI,
- controlar salidas mediante PWM,
- integrar múltiples protocolos en un mismo sistema,
- documentar prácticas técnicas de manera reproducible.

---

## Plataformas

Las prácticas se desarrollan en múltiples microcontroladores para comparar implementaciones y entender las diferencias entre plataformas.

| Plataforma | Lenguaje | Voltaje | WiFi | UART | Notas |
|---|---|---|---|---|---|
| ESP32 | C++ (Arduino IDE) | 3.3V | ✅ | 3 puertos | Plataforma principal |
| Arduino UNO | C++ (Arduino IDE) | 5V | ❌ | 1 puerto | Ideal para aprender |
| Arduino Nano | C++ (Arduino IDE) | 5V | ❌ | 1 puerto | Compacto, igual que UNO |
| Arduino Mega | C++ (Arduino IDE) | 5V | ❌ | 4 puertos | Más pines y UARTs |
| Arduino R4 WiFi | C++ (Arduino IDE) | 3.3V | ✅ | 1 puerto | Factor de forma UNO + WiFi |
| Raspberry Pi Pico W | MicroPython | 3.3V | ✅ | 2 puertos | RP2040 dual-core |

> 📌 Referencia completa de pines: [`00_documentacion/plataformas/pines_por_plataforma.md`](./00_documentacion/plataformas/pines_por_plataforma.md)

---

## Hardware disponible

### Microcontroladores y computadoras

- ESP32, ESP8266, ESP32-CAM
- Arduino R4 WiFi, Arduino UNO, Arduino Nano, Arduino Mega
- Raspberry Pi 4, Raspberry Pi Pico W, Raspberry Pi Pico H, Raspberry Pi Zero

### Sensores

- MPU6050, TMP117, SHTC3, BMP581, OLED I2C

### Componentes electrónicos

- Motores DC, Protoboards, Resistencias, Capacitores, Diodos, LEDs, Cables jumper, Compuertas lógicas

### Fabricación digital y herramientas

- Impresora 3D FDM, Impresora 3D de resina, Estación de curado, CNC láser 2W, Estación de soldadura

---

## Estructura del repositorio

```txt
00_documentacion/
  conceptos/            — Definiciones técnicas de protocolos
  plataformas/          — Referencia de pines por microcontrolador
  troubleshooting/      — Errores comunes y soluciones
01_uart/
  uart_pc_esp32/        — ESP32 (C++ / Arduino IDE)        ✅ Completado
  uart_pc_arduino_uno/  — Arduino UNO / Nano (C++ / Arduino IDE)
  uart_pc_arduino_mega/ — Arduino Mega (C++ / Arduino IDE)
  uart_pc_rpi_pico/     — Raspberry Pi Pico W (MicroPython)
02_i2c/
03_pwm/
04_spi/
05_sistema_integrado/
imagenes/
```

### Descripción de carpetas

| Carpeta | Contenido |
|---|---|
| [`00_documentacion/`](./00_documentacion) | Planes, mapas conceptuales y documentación general |
| [`01_uart/`](./01_uart) | Prácticas relacionadas con UART |
| [`02_i2c/`](./02_i2c) | Sensores y comunicación I2C |
| [`03_pwm/`](./03_pwm) | Control PWM y manejo de salidas |
| [`04_spi/`](./04_spi) | Fundamentos y pruebas SPI |
| [`05_sistema_integrado/`](./05_sistema_integrado) | Integración de múltiples protocolos |
| [`imagenes/`](./imagenes) | Evidencias visuales y capturas |

---

## Metodología de trabajo

Cada práctica debe incluir:

- objetivo,
- materiales utilizados,
- descripción de conexiones,
- código fuente,
- errores encontrados,
- solución aplicada,
- evidencia visual,
- reflexión técnica.

---

## Estado actual

![Fase 1 en progreso](https://img.shields.io/badge/Fase_1-En_progreso-yellow)
![Lenguaje](https://img.shields.io/badge/Lenguaje-C%2B%2B%20%2F%20Arduino-blue)
![Plataforma](https://img.shields.io/badge/Plataforma-ESP32%20%7C%20Arduino-green)
![Licencia](https://img.shields.io/badge/Licencia-MIT-lightgrey)

Actualmente enfocado en la **Fase 1: Comunicaciones en sistemas embebidos**.

| Fase | Tema | Estado |
|------|------|--------|
| Fase 1 | Comunicaciones (UART, I2C, SPI, PWM) | 🔄 En progreso |
| Fase 2 | Sensores y adquisición de datos | ⏳ Pendiente |
| Fase 3 | Control y movimiento | ⏳ Pendiente |
| Fase 4 | Robots móviles autónomos | ⏳ Pendiente |
| Fase 5 | Visión artificial y sistemas avanzados | ⏳ Pendiente |

---

## Necesidad que atiende y origen

El proyecto parte de mi proceso de aprendizaje técnico en robótica competitiva. Busca reunir código, conexiones, errores y evidencias en un mismo lugar para facilitar la consulta y la reproducción de prácticas. Está dirigido a personas que aprenden electrónica, programación embebida y robótica, y que desean compartir sus avances.

## Cómo comenzar

1. Revisa la [metodología de trabajo](00_documentacion/metodologia_trabajo.md) y la [referencia de pines](00_documentacion/plataformas/pines_por_plataforma.md).
2. Comienza con la [práctica UART entre PC y ESP32](01_uart/uart_pc_esp32/README.md), que incluye materiales, configuración, comandos y evidencia documentada.
3. Descarga el repositorio y abre `01_uart/uart_pc_esp32/uart_pc_esp32.ino` en Arduino IDE.
4. Sigue la configuración de placa y conexión indicada en esa práctica. Selecciona el puerto de tu computadora; el puerto documentado corresponde al equipo de la prueba original.
5. Prueba los comandos y compara tus resultados con los documentados. Registra diferencias, errores y la placa utilizada.

La práctica UART con ESP32 cuenta con resultados y fotografías en su documentación. La presencia de código en otras carpetas no implica que todas las prácticas hayan sido validadas físicamente.

## Próximos pasos y colaboración

Se busca ampliar las evidencias de las prácticas, completar instrucciones y registrar pruebas en distintas plataformas, avanzando progresivamente hacia sensores, control e integración de robots.

Puedes proponer mejoras, reportar dificultades al reproducir una práctica, corregir documentación o aportar recursos propios. Consulta [CONTRIBUTING.md](CONTRIBUTING.md) antes de enviar una contribución.

## Uso de inteligencia artificial

Para adaptar la documentación al Laboratorio 6 del curso SINT-741 se utilizó ChatGPT como apoyo para revisar los requisitos, organizar los apartados del README, redactar una guía de contribución y preparar propuestas de Issue y Pull Request a partir del contenido existente. Este apoyo no constituye una validación del hardware ni de los resultados experimentales; las nuevas pruebas deben documentarse con evidencia.

## Reflexión sobre la comunidad

Para que otra persona pueda comprender, utilizar y mejorar este proyecto sin depender de su autora, necesita objetivos claros, materiales y conexiones identificados, instrucciones reproducibles, código accesible, evidencias y una distinción entre lo probado y lo pendiente. También necesita un canal para plantear dudas y un proceso de contribución que permita revisar y conservar los aprendizajes de otras personas.

