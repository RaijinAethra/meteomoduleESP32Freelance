# MeteoSensor: ESP32 Environmental Monitoring Firmware

![PCB 3D Render](renders/Снимок%20экрана%202026-09-21%20131632.png)

Compact and reliable firmware for an ESP32-based weather module. It reads temperature, humidity, and atmospheric pressure from a BME280 sensor and displays the data on an external OLED screen. The BME280 is mounted directly on the main PCB, while the OLED is connected through an external I²C header.

Hardware
Microcontroller: ESP32 Dev Module
Sensor: BME280 — mounted on the main PCB
Display: SSD1306 OLED 128×64 — connected externally
Connection: I²C
USB: USB Type-C for programming, power, and serial communication
Buttons: Two tactile buttons for reset and firmware programming mode

The main PCB is designed to keep the core electronics compact while providing a dedicated connector for the external OLED display. USB Type-C allows the board to be powered and programmed directly, while the two buttons make resetting the ESP32 and entering programming mode simple and convenient.

Software
Framework: Arduino
Platform: PlatformIO
Libraries: Adafruit BME280, Adafruit SSD1306, Adafruit GFX
What it does

The firmware initializes the sensor and display, reads the environmental data every 2 seconds, and shows the current temperature, humidity, and pressure on the OLED. The same data is also sent to the Serial Monitor for easy testing and debugging.