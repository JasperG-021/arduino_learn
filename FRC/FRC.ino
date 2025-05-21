#define FRC A5

#define LED_1 11
#define LED_2 10
#define LED_3 9
#define LED_4 6
#define LED_5 5

void setup() {
  Serial.begin(115200);
  pinMode(FRC, INPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
}

#define CAL 255. / 200.
void loop() {
  // In fact, FRC is just a potentiometer. Just read it
  int val_frc = analogRead(FRC);
  Serial.println(val_frc);

  //A stupid logic....but worked
  if (val_frc < 14) { val_frc = 0; }
  if (200 * 1 < val_frc) {
    analogWrite(LED_1, 255);
    if (200 * 2 < val_frc) {
      analogWrite(LED_2, 255);
      if (200 * 3 < val_frc) {
        analogWrite(LED_3, 255);
        if (200 * 4 < val_frc) {
          analogWrite(LED_4, 255);
          if (200 * 5 < val_frc) {
            analogWrite(LED_5, 255);
          } else {
            val_frc = val_frc - 200 * 4;
            analogWrite(LED_5, val_frc * CAL);
          }
        } else {
          val_frc = val_frc - 200 * 3;
          analogWrite(LED_4, val_frc * CAL);
        }
      } else {
        val_frc = val_frc - 200 * 2;
        analogWrite(LED_3, val_frc * CAL);
      }
    } else {
      val_frc = val_frc - 200 * 1;
      analogWrite(LED_2, val_frc * CAL);
    }
  } else {
    val_frc = val_frc - 200 * 0;
    analogWrite(LED_1, val_frc * CAL);
  }

  delay(100);
  analogWrite(LED_1, 0);
  analogWrite(LED_2, 0);
  analogWrite(LED_3, 0);
  analogWrite(LED_4, 0);
  analogWrite(LED_5, 0);
}
