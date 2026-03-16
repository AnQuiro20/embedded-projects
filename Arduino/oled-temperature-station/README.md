# Arduino OLED Temperature Station

Proyecto simple de una mini estación de temperatura y humedad usando Arduino.

El sistema utiliza un sensor DHT11 para medir temperatura y humedad y muestra los datos en una pantalla OLED.

## Componentes

- Arduino UNO
- Pantalla OLED SSD1306
- Sensor DHT11
- Protoboard
- Cables Dupont

## Conexiones

### OLED

GND → GND  
VCC → 5V  
SCL → A5  
SDA → A4  

### DHT11

VCC → 5V  
GND → GND  
DATA → Pin 2  

## Funcionalidad

El Arduino lee la temperatura y humedad cada pocos segundos y las muestra en la pantalla OLED.

## Autor

Andres Quirós
