int pin_bi = 10;
int pin_fi = 11;
int pin_ms = A5;
int pin_turn = A2;

int ms;
int val_button;
int val_button_old;
int state_direction;
int state_direction_old = 1;

void setup() {
  Serial.begin(115200);
  pinMode(pin_ms, INPUT);
  pinMode(pin_turn, INPUT_PULLUP);
  pinMode(pin_bi, OUTPUT);
  pinMode(pin_fi, OUTPUT);
}

void loop() {
  ms = speed_control();
  state_direction = button_control();
  motor_control(state_direction, ms);
  delay(200);
}


int speed_control() {
  ms = analogRead(pin_ms);
  ms = (ms * 175. / 1023.) + 80;
  return ms;
}

int button_control() {
  // state_direction loop : 0, 1, 0, -1, 0, 1, 0, -1.....
  val_button = digitalRead(pin_turn);
  if (val_button == 0 && val_button_old == 1) {
    if (state_direction != 0) {
      state_direction = 0;
    } else {
      state_direction = -state_direction_old;
      state_direction_old = state_direction;
    }
  }
  val_button_old = val_button;
  // Serial.println("state_direction: " + String(state_direction) + "; state_direction_old: " + String(state_direction_old));
  return state_direction;
}

void motor_control(int direction, int ms) {
  //one button control three types
  if (direction == 1) {
    analogWrite(pin_bi, ms);
    analogWrite(pin_fi, 0);
  }
  if (direction == -1) {
    analogWrite(pin_bi, 0);
    analogWrite(pin_fi, ms);
  }
  if (direction == 0) {
    analogWrite(pin_bi, 0);
    analogWrite(pin_fi, 0);
  }
}
