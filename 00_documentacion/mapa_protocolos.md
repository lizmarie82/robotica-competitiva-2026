# Mapa general de protocolos de comunicación

| Protocolo | Líneas principales | Tipo de comunicación | Ventajas | Limitaciones | Uso en robótica |
|---|---|---|---|---|---|
| UART | TX, RX, GND | Serial punto a punto | Simple, útil para debug | Pocos dispositivos | Raspberry Pi ↔ ESP32 |
| I2C | SDA, SCL, VCC, GND | Bus compartido | Varios sensores con pocos cables | Más sensible al ruido | Sensores como MPU6050, TMP117, SHTC3 |
| SPI | MOSI, MISO, SCK, CS | Comunicación rápida | Alta velocidad | Más cables | Pantallas, SD, sensores rápidos |
| PWM | Señal, GND | Control por pulsos | Controla potencia o señal | No transmite datos complejos | Motores, LEDs, servos |

## Reflexión inicial

En un robot autónomo, no todos los componentes se comunican igual. Los sensores pueden usar I2C, las placas pueden comunicarse por UART, algunos periféricos rápidos pueden usar SPI y los motores se controlan mediante PWM.

Comprender estas diferencias ayuda a diseñar sistemas más ordenados, confiables y fáciles de depurar.
