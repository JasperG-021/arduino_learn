int pin_bi = 10;
int pin_fi = 11;
int pin_ms = A5;
int pin_turn = A2;

int val_button;
int val_button_old;
int state_direction;
int state_direction_old;

void setup() {
  Serial.begin(115200);
  pinMode(pin_ms, INPUT);
  pinMode(pin_turn, INPUT_PULLUP);
  pinMode(pin_bi, OUTPUT);
  pinMode(pin_fi, OUTPUT);
}

void loop() {
  int ms;
  ms = analogRead(pin_ms);
  ms = (ms * 175. / 1023.) + 80;
  val_button = digitalRead(pin_turn);
  if (val_button == 0 && val_button_old == 1) {
    state_direction = !state_direction;
  }
  val_button_old = val_button;

  start_analog(state_direction, ms);
  if (state_direction != state_direction_old) {
    stop_analog();
    delay(1000);
    start_analog(state_direction, ms);
  }
  state_direction_old = state_direction;
  delay(200);
}


void stop_analog() {
  analogWrite(pin_bi, 0);
  analogWrite(pin_fi, 0);
}

void start_analog(int direction, int ms) {
  if (direction == 1) {
    analogWrite(pin_bi, ms);
    analogWrite(pin_fi, 0);
  } else {
    analogWrite(pin_bi, 0);
    analogWrite(pin_fi, ms);
  }

int status_button
}
