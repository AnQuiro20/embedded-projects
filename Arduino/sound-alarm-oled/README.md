# Arduino Sound Alarm with OLED

Este proyecto detecta sonidos fuertes utilizando un sensor de sonido y muestra una alerta en una pantalla OLED.

Cuando el sensor detecta ruido:

- La pantalla OLED muestra "ALERTA!"
- Se enciende un LED
- Suena un buzzer

Cuando no hay ruido:

- La pantalla muestra "Silencio"

## Componentes

- Arduino UNO
- Sensor de sonido (KY-037)
- Pantalla OLED SSD1306
- Buzzer activo
- LED
- Resistencia
- Protoboard
- Cables Dupont

## Conexiones

OLED:
GND → GND  
VCC → 5V  
SDA → A4  
SCL → A5  

Sensor de sonido:
VCC → 5V  
GND → GND  
DO → Pin 7  

LED:
Pin 5 → LED → resistencia → GND

Buzzer:
Pin 6 → buzzer +
GND → buzzer -

## Autor

Andres Quirós

