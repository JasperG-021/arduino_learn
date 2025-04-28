#include <Stepper.h>
#define STEP_AROUND 2038.
#define RPM 15
Stepper stepper_motor_test(STEP_AROUND, 2, 3, 4, 5);

int pin_10 = A4;
int pin_1 = A5;
int pin_010 = A0;
int pin_01 = A1;

int val_button_10_old;
int val_button_010_old;

float STEP_ONE_DEGREE = STEP_AROUND / 360.;

void setup() {
  Serial.begin(115200);
  pinMode(pin_10, INPUT_PULLUP);
  pinMode(pin_1, INPUT_PULLUP);
  pinMode(pin_010, INPUT_PULLUP);
  pinMode(pin_01, INPUT_PULLUP);
}

void loop() {
  int val_empt = 9;
  int val_button_10 = digitalRead(pin_10);
  int val_button_1 = digitalRead(pin_1);
  int val_button_010 = digitalRead(pin_010);
  int val_button_01 = digitalRead(pin_01);

  button_control(val_button_10, STEP_ONE_DEGREE*10, val_button_10_old);
  button_control(val_button_1, STEP_ONE_DEGREE, val_empt);
  button_control(val_button_010, -STEP_ONE_DEGREE*10, val_button_010_old);
  button_control(val_button_01, -STEP_ONE_DEGREE, val_empt);

  delay(100);
}

void button_control(int val, int degree, int &val_old) {
  if (val_old != 9) {
    if (val == 0 && val_old == 1) {
      step_motor(degree);
    }
  } else {
    if (val == 0) {
      step_motor(degree);
    }
  }
  val_old = val;
}

void step_motor(int degree) {
  stepper_motor_test.setSpeed(RPM);
  stepper_motor_test.step(degree);
}
