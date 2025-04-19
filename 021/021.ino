int br = 115200;

int redPin = 3;
int greenPin = 6;
int bluePin = 9;

int con = 0;
int ledBri = 50;
int ledChangeDelay = 100;
int whileDelay = 500;
int blinksNum;
void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  Serial.println("Set The Blinks....");
  while(Serial.available() == 0){}
  blinksNum = Serial.parseFloat();
  Serial.print("blinksNum: ");
  Serial.println(blinksNum);
  // for (con=0; con<blinksNum; con+=1) {  }
  while(con < blinksNum){
      Serial.println(con);
      analogWrite(redPin, ledBri);
      delay(ledChangeDelay);
      analogWrite(redPin, 0);
      analogWrite(greenPin, ledBri);
      delay(ledChangeDelay);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, ledBri);
      delay(ledChangeDelay);
      analogWrite(bluePin, 0);

      delay(whileDelay);
      con+=1;
  }
  con = 0;
  Serial.println("Loop Over.");
}