#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("No se encontro la pantalla OLED");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 10);
  display.println("Iniciando...");
  display.display();

  delay(2000);
}

void loop() {
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error leyendo el DHT11");

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 20);
    display.println("Error leyendo");
    display.println("el sensor DHT11");
    display.display();

    delay(2000);
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(20, 5);
  display.println("Mini Estacion");

  display.setTextSize(2);
  display.setCursor(10, 22);
  display.print(temperatura);
  display.println(" C");

  display.setTextSize(1);
  display.setCursor(10, 50);
  display.print("Humedad: ");
  display.print(humedad);
  display.println(" %");

  display.display();

  delay(2000);
}
