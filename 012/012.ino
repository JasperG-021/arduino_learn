int br = 9600;
int waitT = 500; 

int potPin = A0;
int LedPin = 3;
float potVal;
int analogNum;

float cal = 255./1023.;

void setup() {
  Serial.begin(br);
  pinMode(potPin, INPUT);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  potVal = analogRead(potPin);
  analogNum = cal * potVal;

  analogWrite(LedPin, analogNum);

  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print("; ");
  Serial.print("analogNum: ");
  Serial.println(analogNum);
  delay(waitT);
}
