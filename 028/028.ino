#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
int x = 0;
int y = 0;

int x_state = 1;
int y_state = 1;

int br = 115200;
int dt = 100;

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

void setup() {
  Serial.begin(br);
  matrix.begin();
}

void loop() {
  x = x + x_state;
  y = y + y_state;

  if (x <= 0 || 11 <= x) {
    x_state = -x_state;
  }

  if (y <= 0 || 7 <= y) {
    y_state = -y_state;
  }

  frame[y][x] = !frame[y][x];
  matrix.renderBitmap(frame, 8, 12);
  frame[y][x] = !frame[y][x];
  delay(dt);
}
