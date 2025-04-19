int br = 9600;
int redPin = 2;
int greenPin = 7;
int yellowPin = 8;

String myColor;

void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop() {
  Serial.println("Please Enter Your color...");

  while (Serial.available() == 0) {
  }

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);

  myColor = Serial.readString();
  Serial.println("The word you input is : " + myColor);
  myColor.toLowerCase();

  if (myColor == "red") {
    digitalWrite(redPin, HIGH);
    Serial.println("Red LED is on.");
  }
  if (myColor == "green") {
    digitalWrite(greenPin, HIGH);
    Serial.println("Green LED is on.");
  }
  if (myColor == "yellow") {
    digitalWrite(yellowPin, HIGH);
    Serial.println("Yellow LED is on.");
  }
  if(myColor != "red" && myColor != "green" && myColor != "yellow"){
    Serial.println("We Don't Have That LED.");
  }
}