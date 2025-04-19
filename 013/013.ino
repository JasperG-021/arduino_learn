int br = 9600;
int waitT = 200; 

int potPin = A0;
int LedPin = 3;
float potVal;
float analogVal;

void setup() {
  Serial.begin(br);
  pinMode(potPin, INPUT);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  potVal = analogRead(potPin);
  analogVal = pow(2, potVal/127.875) - 1.;

  analogWrite(LedPin, analogVal);

  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print("; ");
  Serial.print("analogVal: ");
  Serial.println(analogVal);
  delay(waitT);
}
