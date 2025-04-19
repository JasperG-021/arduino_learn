#include <Servo.h>
int br = 115200;
int servoPin = 9;
int potPin = A0;


int servoAngle;
int analogNum;

int delayTime = 50;
float cal = 180./1023.;

Servo myServo;

void setup() {
  Serial.begin(br);
  myServo.attach(servoPin);
  pinMode(potPin, INPUT);
}

void loop() {  
  while (servoAngle == analogNum) {
    // 0~1023/0~180
    servoAngle = analogRead(potPin) * cal;
    delay(delayTime);
  }
  myServo.write(servoAngle);
  analogNum = servoAngle;
}
