int L8 = 9;
int L4 = 10;
int L2 = 11;
int L1 = 12;

int delayTime = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //1
  digitalWrite(L1, 1);
  delay(delayTime);
  digitalWrite(L1, 0);
  delay(delayTime);
  //2
  digitalWrite(L1, 0);
  digitalWrite(L2, 1);
  delay(delayTime);
  digitalWrite(L1, 0);
  digitalWrite(L2, 0);
  delay(delayTime);
  //3
  digitalWrite(L1, 1);
  digitalWrite(L2, 1);
  delay(delayTime);
  digitalWrite(L1, 0);
  digitalWrite(L2, 0);
  delay(delayTime);
  //4
  digitalWrite(L4, 1);
  delay(delayTime);
  digitalWrite(L4, 0);
  delay(delayTime);
  //5
  digitalWrite(L1, 1);
  digitalWrite(L4, 1);
  delay(delayTime);
  digitalWrite(L1, 0);
  digitalWrite(L4, 0);
  delay(delayTime);
  //6
  digitalWrite(L2, 1);
  digitalWrite(L4, 1);
  delay(delayTime);
  digitalWrite(L2, 0);
  digitalWrite(L4, 0);
  delay(delayTime);
  //7
  digitalWrite(L1, 1);
  digitalWrite(L2, 1);
  digitalWrite(L4, 1);
  delay(delayTime);
  digitalWrite(L1, 0);
  digitalWrite(L2, 0);
  digitalWrite(L4, 0);
  delay(delayTime);
  //8
  digitalWrite(L8, 1);
  delay(delayTime);
  digitalWrite(L8, 0);
  delay(delayTime);
  //9
  digitalWrite(L1, 1);
  digitalWrite(L8, 1);
  delay(delayTime);
  digitalWrite(L1, 0);
  digitalWrite(L8, 0);
  delay(delayTime);
  //10
  digitalWrite(L2, 1);
  digitalWrite(L8, 1);
  delay(delayTime);
  digitalWrite(L2, 0);
  digitalWrite(L8, 0);
  delay(delayTime);
  //11
  digitalWrite(L1, 1);
  digitalWrite(L2, 1);
  digitalWrite(L8, 1);
  delay(delayTime);
  digitalWrite(L1, 0);
  digitalWrite(L2, 0);
  digitalWrite(L8, 0);
  delay(delayTime);
  //12
  digitalWrite(L4, 1);
  digitalWrite(L8, 1);
  delay(delayTime);
  digitalWrite(L4, 0);
  digitalWrite(L8, 0);
  delay(delayTime);
  //13
  digitalWrite(L1, 1);
  digitalWrite(L4, 1);
  digitalWrite(L8, 1);
  delay(delayTime);
  digitalWrite(L1, 0);
  digitalWrite(L4, 0);
  digitalWrite(L8, 0);
  delay(delayTime);
  //14
  digitalWrite(L2, 1);
  digitalWrite(L4, 1);
  digitalWrite(L8, 1);
  delay(delayTime);
  digitalWrite(L2, 0);
  digitalWrite(L4, 0);
  digitalWrite(L8, 0);
  delay(delayTime);
  //15
  digitalWrite(L1, 1);
  digitalWrite(L2, 1);
  digitalWrite(L4, 1);
  digitalWrite(L8, 1);
  delay(delayTime);
  digitalWrite(L1, 0);
  digitalWrite(L2, 0);
  digitalWrite(L4, 0);
  digitalWrite(L8, 0);
  delay(delayTime);
}