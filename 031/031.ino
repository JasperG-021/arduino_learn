#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
byte frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
#include <DHT.h>
#define DHTPIN 13
#define DHTTYPE DHT11
DHT DHT_my(DHTPIN, DHTTYPE);

int br = 115200;
int time_com = 100;
int pin_r = 4;
int pin_y = 3;
int pin_g = 2;

int scroll_speed = 50;
int val_r;
int val_y;
int val_g;
float temp_c;
float temp_f;
float hum;
float HIC;
float HIF;
int cnt;

String message_temp;
String message_hum;
String message_HI;

void setup() {
  Serial.begin(br);
  pinMode(pin_r, INPUT_PULLUP);
  pinMode(pin_y, INPUT_PULLUP);
  pinMode(pin_g, INPUT_PULLUP);

  DHT_my.begin();
  matrix.begin();

  delay(time_com * 10);
}

void loop() {
  //Communication frequency is 100ms, for protect DHT.
  if (cnt % 10 == 0) {
    temp_c = DHT_my.readTemperature();
    temp_f = DHT_my.readTemperature(true);
    hum = DHT_my.readHumidity();

    if (isnan(temp_c) || isnan(temp_f) || isnan(hum)) {
      Serial.println("Failed to Read Data on DHT11");
      delay(time_com);
      return;
    }
    HIC = DHT_my.computeHeatIndex(temp_c, hum, false);
    HIF = DHT_my.computeHeatIndex(temp_f, hum);

    cnt = 0;
  }
  cnt = cnt + 1;

  val_r = digitalRead(pin_r);
  val_y = digitalRead(pin_y);
  val_g = digitalRead(pin_g);

  // textScroll will influence loop speed, have to put it in if
  if (val_r == 0) {
    matrix.beginDraw();
    matrix.textScrollSpeed(scroll_speed);
    matrix.textFont(Font_5x7);
    matrix.beginText(5, 1, 255, 0, 0);
    message_temp = "Temp:" + String(temp_c) + "°C " + String(temp_f) + "°F";
    matrix.println(message_temp);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
  }
  if (val_g == 0) {
    matrix.beginDraw();
    matrix.textScrollSpeed(scroll_speed);
    matrix.textFont(Font_5x7);
    matrix.beginText(5, 1, 255, 0, 0);
    message_hum = "Hum:" + String(hum) + "% ";
    matrix.println(message_hum);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
  }
  if (val_y == 0) {
    matrix.beginDraw();
    matrix.textScrollSpeed(scroll_speed);
    matrix.textFont(Font_5x7);
    matrix.beginText(5, 1, 255, 0, 0);
    message_HI = "HIC:" + String(HIC) + "°C " + String(HIF) + "°F";
    matrix.println(message_HI);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
  }
  delay(time_com);
}
