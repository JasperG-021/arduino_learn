#include <Stepper.h>
#define STEP_AROUND 2038.
#define RPM 15
#define STEP_ONE_DEGREE STEP_AROUND / 360.
Stepper stepper_motor_test(STEP_AROUND, 2, 3, 4, 5);

#define PIN_F90 A4
#define PIN_F10 A5
#define PIN_B90 A0
#define PIN_B10 A1

int val_button_f90_old;
int val_button_b90_old;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_F90, INPUT_PULLUP);
  pinMode(PIN_F10, INPUT_PULLUP);
  pinMode(PIN_B90, INPUT_PULLUP);
  pinMode(PIN_B10, INPUT_PULLUP);
}

void loop() {
  int val_button_f90 = digitalRead(PIN_F90);
  int val_button_f10 = digitalRead(PIN_F10);
  int val_button_b90 = digitalRead(PIN_B90);
  int val_button_b10 = digitalRead(PIN_B10);

  button_control(val_button_f90, STEP_ONE_DEGREE * 90, val_button_f90_old);
  button_control(val_button_f10, STEP_ONE_DEGREE * 10, 9);
  button_control(val_button_b90, -STEP_ONE_DEGREE * 90, val_button_b90_old);
  button_control(val_button_b10, -STEP_ONE_DEGREE * 10, 9);

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
