int pin9 = 9;

int bright2 = 2;
int bright4 = 4;
int bright8 = 8;
int bright16 = 16;
int bright32 = 32;
int bright64 = 64;
int bright128 = 128;
int bright256 = 255;

int delayTime = 300;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin9, 1);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pin9, bright2);
  delay(delayTime);
  analogWrite(pin9, bright4);
  delay(delayTime);
  analogWrite(pin9, bright8);
  delay(delayTime);
  analogWrite(pin9, bright16);
  delay(delayTime);
  analogWrite(pin9, bright32);
  delay(delayTime);
  analogWrite(pin9, bright64);
  delay(delayTime);
  analogWrite(pin9, bright128);
  delay(delayTime);
  analogWrite(pin9, bright256);
  delay(delayTime);
}
