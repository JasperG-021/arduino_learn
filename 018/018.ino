int br = 115200;
int redPin=3;
int greenPin=6;
int bluePin=9;

String ledCol;

void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  //get color
  Serial.println("Please set the color...");
  while (Serial.available() == 0) {}
  ledCol = Serial.readString();
  //lowercase String
  ledCol.toLowerCase();

  //LED OFF
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);

  if(ledCol != "red" && ledCol != "green" && ledCol != "blue" && ledCol != "cyan" && ledCol != "magenta" && ledCol != "yellow" && ledCol != "orange" && ledCol != "white"){
    Serial.println("We Don't Have That Color.");
  }else {
    //Set LED
    // red(255,0,0)
    if (ledCol == "red") {
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      Serial.println("Red is ON");
    }
    // green(0,255,0)
    if (ledCol == "green") {
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      Serial.println("Green is ON");
    }
    // blue(0,0,255)
    if (ledCol == "blue") {
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 255);
      Serial.println("Blue is ON");
    }
    // cyan(0,255,255)
    if (ledCol == "cyan") {
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 150);
      Serial.println("Cyan is ON");
    }
    // magenta(255,0,255)
    if (ledCol == "magenta") {
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 100);
      Serial.println("Magenta is ON");
    }
    // yellow(255,255,0)
    if (ledCol == "yellow") {
      analogWrite(redPin, 255);
      analogWrite(greenPin, 100);
      analogWrite(bluePin, 0);
      Serial.println("Yellow is ON");
    }
    // orange(255,165,0)
    if (ledCol == "orange") {
      analogWrite(redPin, 255);
      analogWrite(greenPin, 30);
      analogWrite(bluePin, 0);
      Serial.println("Orange is ON");
    }
    // white(255,255,255)
    if (ledCol == "white") {
      analogWrite(redPin, 255);
      analogWrite(greenPin, 120);
      analogWrite(bluePin, 94);
      Serial.println("White is ON");
    }
  }
}
