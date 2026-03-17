# ESP32 Weather Dashboard

Proyecto de estación meteorológica usando ESP32 que muestra temperatura y humedad en una página web accesible desde cualquier dispositivo en la misma red.

## Características

- Servidor web en ESP32
- Lectura de temperatura y humedad (DHT11)
- Interfaz web moderna tipo dashboard
- Actualización automática
- Diseño responsive (funciona en celular)

## Componentes

- ESP32
- Sensor DHT11
- Protoboard
- Cables Dupont

## Conexiones

| DHT11 | ESP32 |
|------|------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 4 |

## Funcionamiento

1. El ESP32 se conecta a WiFi
2. Inicia un servidor web
3. Mide temperatura y humedad
4. Muestra los datos en una página web

## Acceso

1. Conectar a la misma red WiFi
2. Abrir navegador
3. Ingresar la IP del ESP32

## Resultado

(agregar imagen aquí)

## Autor

Andres Quirós
