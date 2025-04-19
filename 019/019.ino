int br = 115200;

int redPin = 3;
int greenPin = 6;
int bluePin = 9;

int con = 0;
int ledChangeDelay = 100;
int whileDelay = 500;
void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  Serial.println("Enter anything to start the loop....");
  while(Serial.available() == 0){}
  Serial.readString();
  while(con < 25){
      Serial.println(con);
      analogWrite(redPin, 50);
      delay(ledChangeDelay);
      analogWrite(redPin, 0);
      analogWrite(greenPin, 50);
      delay(ledChangeDelay);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 50);
      delay(ledChangeDelay);
      analogWrite(bluePin, 0);
      
      delay(whileDelay);
      con += 1;
  }
  con = 0;
}