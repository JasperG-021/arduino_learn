#include <Servo.h>
Servo servo_test;

int br = 115200;
int time_com = 100;

int pin_light = A0;
int pin_servo = 11;
int pin_LED = 3;

int val_light;
int val_light_old;

float cal_angle = 180. / 1023.;
float cal_LED = 255. / 1023.;
void setup() {
  Serial.begin(br);
  servo_test.attach(pin_servo);
  pinMode(pin_light, INPUT);
  pinMode(pin_LED, OUTPUT);
}

void loop() {
  //react when val_light change
  while (val_light == val_light_old) {
    val_light = analogRead(pin_light);
    delay(time_com);
  }
  val_light_old = val_light;
  Serial.println(String(val_light) + ", " + String(255 - val_light * cal_LED) + ", " + String(180 - val_light * cal_angle));

  //0~1023/255/0
  analogWrite(pin_LED, 255 - val_light * cal_LED);
  // 0~1023/180~0
  servo_test.write(180 - val_light * cal_angle);
}
