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
int br = 115200;
int pin_start_button = 7;
int pin_up = 3;
int pin_down = 2;
int cnt = 0;
int ball_speed = 3;

int x_ball;
int y_ball;
int x_ball_state = 1;
int y_ball_state = 1;

int read_start_button;
int read_start_button_old;
int read_up;
int read_up_old;
int read_down;
int read_down_old;

int y_racket = 4;
int x_racket = 0;
int dt = 100;

void setup() {
  matrix.begin();
  pinMode(pin_up, INPUT_PULLUP);
  pinMode(pin_down, INPUT_PULLUP);
  pinMode(pin_start_button, INPUT_PULLUP);
  //Set start position. Push the RED button to start game. Already have restart button.
  while (true) {
    read_start_button = digitalRead(pin_start_button);

    read_up = digitalRead(pin_up);
    read_down = digitalRead(pin_down);
    if (read_up_old == 0 && read_up == 1 && 0 < y_racket) { y_racket = y_racket - 1; }
    if (read_down_old == 0 && read_down == 1 && y_racket < 7) { y_racket = y_racket + 1; }

    read_up_old = read_up;
    read_down_old = read_down;
    //Put ball on the racket.
    x_ball = x_racket + 1;
    y_ball = y_racket;
    frame[y_racket - 1][x_racket] = !frame[y_racket - 1][x_racket];
    frame[y_racket][x_racket] = !frame[y_racket][x_racket];
    frame[y_ball][x_ball] = !frame[y_ball][x_ball];
    matrix.renderBitmap(frame, 8, 12);
    frame[y_racket - 1][x_racket] = !frame[y_racket - 1][x_racket];
    frame[y_racket][x_racket] = !frame[y_racket][x_racket];
    frame[y_ball][x_ball] = !frame[y_ball][x_ball];
    // Start game
    if (read_start_button == 0) {
      break;
    }
    delay(dt);
  }
}

void loop() {
  //Change racket's position.
  read_up = digitalRead(pin_up);
  read_down = digitalRead(pin_down);
  //Limit the range, one put one pixel.
  //The racket be widened, so the range should be change from 0-7 to 1-7
  //when x_ball==0, game over, can't move.
  if (x_ball != 0) {
    if(read_up_old == 0 && read_up == 1 && 0 < y_racket){y_racket = y_racket - 1; }
    if(read_down_old == 0 && read_down == 1 && y_racket < 7){y_racket = y_racket + 1; }
    
    read_up_old = read_up;
    read_down_old = read_down;
  }
  //bright
  //Widening the racket to increase the gaming experience
  frame[y_ball][x_ball] = !frame[y_ball][x_ball];
  frame[y_racket - 1][x_racket] = !frame[y_racket - 1][x_racket];
  frame[y_racket][x_racket] = !frame[y_racket][x_racket];
  matrix.renderBitmap(frame, 8, 12);
  frame[y_ball][x_ball] = !frame[y_ball][x_ball];
  frame[y_racket - 1][x_racket] = !frame[y_racket - 1][x_racket];
  frame[y_racket][x_racket] = !frame[y_racket][x_racket];
  //Increase the judgment range.
  if (x_ball != 0 || y_ball == y_racket || y_ball == y_racket - 1) {
    //contrl ball's speed
    if (cnt % ball_speed == 0) {
      x_ball = x_ball + x_ball_state;
      y_ball = y_ball + y_ball_state;
      if (y_ball == 0 || y_ball == 7) {
        y_ball_state = -y_ball_state;
      }
      if (x_ball == 0 || x_ball == 11) {
        x_ball_state = -x_ball_state;
      }
    }
    cnt = cnt + 1;
  } else {
    frame[y_ball][0] = 0;
    for (cnt = 1; cnt < 12; cnt = cnt + 1) {
      frame[y_ball][cnt] = 1;
    }
  }
  delay(dt);
}