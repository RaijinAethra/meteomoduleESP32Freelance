#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Adafruit_BME280 bme; // I2C

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Инициализация I2C для ESP32 (стандартные пины GPIO 21 (SDA) и GPIO 22 (SCL))
  Wire.begin(21, 22);

  // Инициализация OLED дисплея (адрес 0x3C)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while(1);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Meteo Station Init...");
  display.display();
  delay(2000);

  // Инициализация датчика BME280 (адрес 0x76 или 0x77)
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("BME280 Error!");
    display.display();
    while (1);
  }
}

void loop() {
  float temp = bme.readTemperature();
  float hum = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F / 1.333224; // Перевод в мм рт. ст.

  // Вывод в монитор порта
  Serial.printf("Temp: %.2f C | Hum: %.2f %% | Press: %.2f mmHg\n", temp, hum, pressure);

  // Вывод на OLED дисплей
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("=== METEO STATION ===");
  
  display.setCursor(0, 16);
  display.printf("Temp: %.1f C", temp);

  display.setCursor(0, 32);
  display.printf("Hum:  %.1f %%", hum);

  display.setCursor(0, 48);
  display.printf("Press:%.1f mmHg", pressure);

  display.display();
  
  delay(2000);
}