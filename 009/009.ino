int baud = 9600;

int LedPin = 7;
int oneSecond = 1000;
String messOn = "LED is on.";
String messOff = "LED is off.";

void setup() {
  // put your setup code here, to run once:
  pinMode(LedPin, OUTPUT);
  Serial.begin(baud);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LedPin, HIGH);
  Serial.println(messOn);
  delay(oneSecond);
  digitalWrite(LedPin, LOW);
  Serial.println(messOff);
  delay(oneSecond);
}
