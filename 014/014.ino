int br = 9600;
int LedPin = 3;

float val;
int valCal;

void setup() {
  Serial.begin(br);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  Serial.println("put your number between 0 to 10...");
  while (Serial.available() == 0) {}
  val = Serial.parseFloat();
  if( 0 < val){
    if(val < 10){
      valCal = pow(2, val/1.25); // 0 < val < 10
    }
    else {valCal = 255;} // 10 <= val
  }
  else{valCal = 0;} // val <= 0 
  analogWrite(LedPin, valCal);
  Serial.print("your number is : ");
  Serial.print(val);
  Serial.print("; analogWrite: ");
  Serial.println(valCal);
}
