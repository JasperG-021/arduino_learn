int pin_read = 8;
int motion;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pin_read, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  motion = digitalRead(pin_read);
  Serial.println(motion);
  delay(100);
}
