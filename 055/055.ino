//BMP
#include <Adafruit_BMP085.h>
Adafruit_BMP085 BP;
//OLED
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//OLED
#define I2C_ADRESS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_RESET -1
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, SCREEN_RESET);
//BUTTON
#define PIN_BUTTON 2

int val_button_old;

void setup() {
  Serial.begin(115200);
  oled.begin(SSD1306_SWITCHCAPVCC, I2C_ADRESS);
  
  pinMode(PIN_BUTTON, INPUT_PULLUP);

  bool BMP_connected = BP.begin();
  if (BMP_connected == true) {
    oled_text(1);
    oled.println("BMP180 was Connected");
    oled.println("--------------------");
    oled.println("Press BLUE button to start test");
    oled.println("--------------------");
  } else {
    oled_text(2);
    oled.println("BMP180 NOTFound");
  }
  oled.display();
}

void loop() {
  int val_button = digitalRead(PIN_BUTTON);
  if (val_button_old == 1 && val_button == 0) {
    float temp_C = BP.readTemperature();
    int pressure = BP.readPressure();
    oled_text(2);
    oled.println("Tem:" + String(temp_C) + "C");
    oled.println("Pre:");
    oled.println(String(pressure) + "Pa");
    oled.display();
  }
  val_button_old = val_button;
  delay(200);
}

void oled_text(int word_size) {
  oled.setCursor(0, 10);
  oled.setTextColor(WHITE);
  oled.setTextSize(word_size);
  oled.clearDisplay();
  oled.display();
}