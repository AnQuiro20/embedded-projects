#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int soundSensor = 7;
int buzzer = 6;
int led = 5;

void setup() {
  pinMode(soundSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED no encontrada");
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  int sound = digitalRead(soundSensor);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);

  if (sound == LOW) {
    display.setCursor(15, 20);
    display.println("ALERTA!");

    digitalWrite(led, HIGH);
    tone(buzzer, 1200);
  } else {
    display.setCursor(10, 20);
    display.println("Silencio");

    digitalWrite(led, LOW);
    noTone(buzzer);
  }

  display.display();

  delay(200);
}
