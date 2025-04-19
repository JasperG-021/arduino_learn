int pin_button = 2;
int pin_buzzer = 8;
int dt = 50;

void setup() {
  Serial.begin(115200);
  pinMode(pin_button, INPUT_PULLUP);
  pinMode(pin_buzzer, OUTPUT);
}

void loop() {
  set_buzzer();
  delay(dt);
}

void read_val(int &val_button) {
  val_button = digitalRead(pin_button);
}

void set_buzzer() {
  int val_button;
  read_val(val_button);
  if (val_button == 0) {
    digitalWrite(pin_buzzer, HIGH);
  } else {
    digitalWrite(pin_buzzer, LOW);
  }
}