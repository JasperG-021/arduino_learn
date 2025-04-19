int br = 115200;
int butIn = 7;
int ledPin = 2;

int butVal;
int st = 0;

int delayTime = 100;

void setup() {
  Serial.begin(br);
  pinMode(butIn, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  butVal = digitalRead(butIn);
  if (butVal == 0) {

    delay(delayTime);
    butVal = digitalRead(butIn);

    if(butVal != 0){
      if(st == 0){
        st = 1;
        digitalWrite(ledPin, st);      
      }else{
        st = 0;
        digitalWrite(ledPin, st);
      }
    }
  }
}
