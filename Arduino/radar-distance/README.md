# Arduino Distance Radar

Proyecto simple de radar de distancia usando Arduino y sensor ultrasónico HC-SR04.

El sistema mide la distancia a un objeto y enciende LEDs dependiendo de qué tan cerca esté.

## Materiales

- Arduino UNO
- Sensor ultrasónico HC-SR04
- 3 LEDs
- 3 resistencias
- Protoboard
- Cables Dupont

## Conexiones

HC-SR04:

VCC → 5V  
GND → GND  
TRIG → Pin 9  
ECHO → Pin 10  

LEDs:

LED 1 → Pin 2  
LED 2 → Pin 3  
LED 3 → Pin 4  

Cada LED conectado a una resistencia y luego a GND.

## Funcionamiento

- +40 cm → ningún LED
- 21–40 cm → LED verde
- 11–20 cm → LED verde + amarillo
- ≤ 10 cm → los tres LEDs encendidos

## Autor

Andres Quirós
