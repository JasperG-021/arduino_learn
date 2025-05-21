#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define I2C_ADRESS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_RESET -1
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, SCREEN_RESET);


#define PIN_BUTTON 2
int val_button_old ;
void setup() {
  Serial.begin(115200);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  oled.begin(SSD1306_SWITCHCAPVCC, I2C_ADRESS);
  oled.clearDisplay();
  oled.display();
}

void loop() {
  int val_button = digitalRead(PIN_BUTTON);
  if (val_button_old == 1 && val_button == 0) {
    oled_text();
    delay(1000);
    oled_pixel();
    delay(1000);
    oled_line();
    delay(1000);
    oled_crosshair();
    delay(1000);
    oled_draw_rect();
    delay(1000);
    oled_fill_rect();
    delay(1000);
    oled_fill_rect_black();
    delay(1000);
    oled_draw_circle();
    delay(1000);
    oled_fill_circle();
    delay(1000);
    oled_ring();
    oled.clearDisplay();
    oled.display();
  }
  val_button_old = val_button;
  delay(1000);
}

void oled_text() {
  oled.clearDisplay();
  oled.setCursor(0, 10);
  oled.setTextColor(WHITE);
  oled.setTextSize(3);
  oled.println(" Hello");
  oled.println(" World");
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}

void oled_pixel() {
  oled.clearDisplay();
  oled.drawPixel(64, 32, WHITE);
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}

void oled_line() {
  oled.clearDisplay();
  oled.drawLine(0, 0, 127, 63, WHITE);
  oled.drawLine(127, 0, 0, 63, WHITE);
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}

void oled_crosshair() {
  oled.clearDisplay();
  oled.drawLine(0, 32, 127, 32, WHITE);
  oled.drawLine(64, 0, 64, 63, WHITE);
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}

void oled_draw_rect() {
  oled.clearDisplay();
  oled.drawRect(0, 0, 128, 64, WHITE);
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}

void oled_fill_rect() {
  oled.clearDisplay();
  oled.fillRect(1, 1, 126, 62, WHITE);
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}

void oled_fill_rect_black() {
  oled.clearDisplay();
  oled.fillRect(0, 0, 128, 64, WHITE);
  oled.fillRect(5, 5, 118, 54, BLACK);
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}

void oled_draw_circle() {
  oled.clearDisplay();
  oled.drawCircle(64, 32, 31, WHITE);
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}

void oled_fill_circle() {
  oled.clearDisplay();
  oled.fillCircle(64, 32, 30, WHITE);
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}

void oled_ring() {
  oled.clearDisplay();
  oled.fillCircle(64, 32, 30, WHITE);
  oled.fillCircle(64, 32, 20, BLACK);
  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
}
