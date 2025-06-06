#define PIN_TRIG 3
#define PIN_ECHO 2

#define sond_speed_cm_s 343 * 100
#define sond_speed_inch_s 767 / 3600 * 5280 * 12

void setup() {
  Serial.begin(115200);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_TRIG, OUTPUT);
}

void loop() {
  int time_ping;
  float time_ping_s;
  float distance_cm;
  float distance_inch;

  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  time_ping = pulseIn(PIN_ECHO, HIGH);
  time_ping_s = time_ping / 1000000.;

  distance_cm = sond_speed_cm_s * time_ping_s / 2;
  distance_inch = sond_speed_inch_s * time_ping_s / 2;
  Serial.println(String(distance_cm) + " cm");
  Serial.println(String(distance_inch) + " inch");
  Serial.println("----------");

  delay(200);
}
