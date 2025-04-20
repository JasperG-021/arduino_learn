int L1 = 12;
int L2 = 11;
int L3 = 10;
int L4 = 9;

int delayTime = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(L1, HIGH);
  delay(delayTime);
  digitalWrite(L1, LOW);
  delay(delayTime);
  digitalWrite(L2, HIGH);
  delay(delayTime);
  digitalWrite(L2, LOW);
  delay(delayTime);
  digitalWrite(L3, HIGH);
  delay(delayTime);
  digitalWrite(L3, LOW);
  delay(delayTime);
  digitalWrite(L4, HIGH);
  delay(delayTime);
  digitalWrite(L4, LOW);
  delay(delayTime);
}
