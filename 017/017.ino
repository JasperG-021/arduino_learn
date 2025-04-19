int br = 9600;
int redPin = 3;
int greenPin = 6;
int yellowPin = 9;

String ledCol;
float ledBri;

float rankVal = 9./8.;

int ledBriCal;

void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop() {
  //get color
  Serial.println("Please set the color...");
  while (Serial.available() == 0){}
  ledCol = Serial.readString();
  //lowercase String
  ledCol.toLowerCase();

  if(ledCol != "red" && ledCol != "green" && ledCol != "yellow"){
    //LED off
    analogWrite(redPin, LOW);
    analogWrite(greenPin, LOW);
    analogWrite(yellowPin, LOW);
    Serial.println("We Don't Have That LED.");
  }
  else{    
    //get brightness
    Serial.println("Please set brightness (between 0 to 9)...");
    while (Serial.available() == 0){}

    //LED off
    analogWrite(redPin, LOW);
    analogWrite(greenPin, LOW);
    analogWrite(yellowPin, LOW);

    ledBri = Serial.parseFloat();

    Serial.println("The color you set is : " + ledCol);
    Serial.print("The Brightness you set is : ");
    Serial.println(ledBri);

    //brightness calculate
    if(0 < ledBri){
      if(ledBri < 9){ledBriCal = pow(2, ledBri/rankVal);}   // 0<ledBri<9
      else{ledBriCal = 255;}   //9<=ledBri
    }
    else{ledBriCal = 0;}   // ledBri<=0  

    //Set LED
    if (ledCol == "red") {
      analogWrite(redPin, ledBriCal);
      Serial.print("Red LED is ON, Brightness is ");
      Serial.println(ledBriCal);
    }
    if (ledCol == "green") {
      analogWrite(greenPin, ledBriCal);
      Serial.print("Green LED is ON, Brightness is ");
      Serial.println(ledBriCal);
    }
    if (ledCol == "yellow") {
      analogWrite(yellowPin, ledBriCal);
      Serial.print("yellow LED is ON, Brightness is ");
      Serial.println(ledBriCal);
    }
  }
}