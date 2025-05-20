#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define I2C_ADRESS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_RESET -1
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, SCREEN_RESET);

#define PIN_BUTTON A0
#define PIN_TRIG 3
#define PIN_ECHO 2

#define SOUND_SPEED_CM_S 343 * 100

int val_button_old;
float val_snoar;
void setup() {
  Serial.begin(115200);
  oled.begin(SSD1306_SWITCHCAPVCC, I2C_ADRESS);
  oled_text(2);
  oled.println("Press BLUEbutton to start test");
  oled.display();


  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_TRIG, OUTPUT);
}

void loop() {
  int val_button = digitalRead(PIN_BUTTON);
  if (val_button_old == 1 && val_button == 0) {
    sona(val_snoar);
    oled_text(3);
    oled.println(val_snoar);
    oled.println("     cm");
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

void sona(float &distance_cm) {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  float time_ping_s = pulseIn(PIN_ECHO, HIGH) / 1000000.;
  distance_cm = SOUND_SPEED_CM_S * time_ping_s / 2.;
  Serial.println(String(distance_cm) + " cm");
  Serial.println("----------");
}