int ledRed = 7;
int ledGreen = 8;

int fastTime = 100;
int slowTime = 500;
int endTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledRed, HIGH);
  delay(fastTime);
  digitalWrite(ledRed, LOW);
  delay(fastTime);
  digitalWrite(ledRed, HIGH);
  delay(fastTime);
  digitalWrite(ledRed, LOW);
  delay(fastTime);
  digitalWrite(ledRed, HIGH);
  delay(fastTime);
  digitalWrite(ledRed, LOW);
  delay(fastTime);
  digitalWrite(ledRed, HIGH);
  delay(fastTime);
  digitalWrite(ledRed, LOW);
  delay(fastTime);
  digitalWrite(ledRed, HIGH);
  delay(fastTime);
  digitalWrite(ledRed, LOW);
  delay(fastTime);

  delay(endTime);

  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);
  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);
  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);
  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);
  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);
  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);
  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);
  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);
  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);
  digitalWrite(ledGreen, HIGH);
  delay(slowTime);
  digitalWrite(ledGreen, LOW);
  delay(slowTime);

  delay(endTime);
}
