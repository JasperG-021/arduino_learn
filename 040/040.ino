void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

void wait() {
  while (Serial.available() == 0) {}
}

float get_length() {
}

int get_c(int a, int b) {
  int c;
  c = a + b;
  return c;
}

val_c = get_c_int(val_a, val_b);
get_c_void(val_a, val_b, val_c);