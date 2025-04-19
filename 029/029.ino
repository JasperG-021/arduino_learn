#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
byte frame[8][12] = {
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0}
};
int br = 115200;
int pin_start_button = 7;
int pin_up = 3;
int pin_down = 2;

float x_ball;
float y_ball;
float speed_ball_x = 0.2;
float speed_ball_y = 0.2;

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
  while(true){
    read_start_button = digitalRead(pin_start_button);

    read_up = digitalRead(pin_up);
    read_down = digitalRead(pin_down);

    if(read_up_old == 0 && read_up == 1 && 0 < y_racket){y_racket = y_racket - 1; }
    if(read_down_old == 0 && read_down == 1 && y_racket < 7){y_racket = y_racket + 1; }
    
    read_up_old = read_up;
    read_down_old = read_down;
    //Put ball on the racket.
    x_ball = x_racket + 1;
    y_ball = y_racket;
    frame[y_racket-1][x_racket] = !frame[y_racket-1][x_racket];
    frame[y_racket][x_racket] = !frame[y_racket][x_racket];
    frame[y_racket+1][x_racket] = !frame[y_racket+1][x_racket];
    frame[int(y_ball)][int(x_ball)] = !frame[int(y_ball)][int(x_ball)];
    matrix.renderBitmap(frame, 8, 12);
    frame[y_racket-1][x_racket] = !frame[y_racket-1][x_racket];
    frame[y_racket][x_racket] = !frame[y_racket][x_racket];
    frame[y_racket+1][x_racket] = !frame[y_racket+1][x_racket];
    frame[int(y_ball)][int(x_ball)] = !frame[int(y_ball)][int(x_ball)];
    // Start game
    if(read_start_button_old == 1 && read_start_button == 0){
      break;
    }
    
    read_start_button_old = read_start_button;
    delay(dt);
  }
}

void loop() {  
  //Change racket's position.
  read_up = digitalRead(pin_up);
  read_down = digitalRead(pin_down);
  //Release to start; Limit the range
  //The racket be widened, so the range should be change from 0-7 to 1-6
  if(read_up_old == 0 && read_up == 1 && 1 < y_racket){y_racket = y_racket - 1; }
  if(read_down_old == 0 && read_down == 1 && y_racket < 6){y_racket = y_racket + 1; }

  read_up_old = read_up;
  read_down_old = read_down;
  //bright
  //Use float to control ball's speed, but it will be flickering. Widening the racket to increase the gaming experience
  frame[y_racket-1][x_racket] = !frame[y_racket-1][x_racket];
  frame[y_racket][x_racket] = !frame[y_racket][x_racket];
  frame[y_racket+1][x_racket] = !frame[y_racket+1][x_racket];
  frame[int(y_ball)][int(x_ball)] = !frame[int(y_ball)][int(x_ball)];
  matrix.renderBitmap(frame, 8, 12);
  frame[y_racket-1][x_racket] = !frame[y_racket-1][x_racket];
  frame[y_racket][x_racket] = !frame[y_racket][x_racket];
  frame[y_racket+1][x_racket] = !frame[y_racket+1][x_racket];
  frame[int(y_ball)][int(x_ball)] = !frame[int(y_ball)][int(x_ball)];
  //Increase the judgment range.
  if(int(x_ball) != 0 || int(y_ball) == y_racket || int(y_ball) == y_racket-1 || int(y_ball) == y_racket+1){
    x_ball = x_ball + speed_ball_x;
    y_ball = y_ball + speed_ball_y;
    if(int(y_ball) == 0 || int(y_ball) == 7){
      speed_ball_y = -speed_ball_y;
    }
    if(int(x_ball) == 0 || int(x_ball) == 11){
      speed_ball_x = -speed_ball_x;
    }
  }
  delay(dt);
}