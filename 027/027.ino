int br = 115200;
int in_r = 2;
int in_g = 3;
int in_b = 4;
int out_r = 9;
int out_g = 10;
int out_b = 11;

int read_r;
int read_g;
int read_b;
int read_r_old = 1;
int read_g_old = 1;
int read_b_old = 1;
int state_r = 0;
int state_g = 0;
int state_b = 0;

int delayTime = 100;

void setup() {
  Serial.begin(br);
  pinMode(in_r, INPUT_PULLUP);
  pinMode(in_g, INPUT_PULLUP);
  pinMode(in_b, INPUT_PULLUP);
  pinMode(out_r, OUTPUT);
  pinMode(out_g, OUTPUT);
  pinMode(out_b, OUTPUT);
}

void loop() {
  read_r = digitalRead(in_r);
  read_g = digitalRead(in_g);
  read_b = digitalRead(in_b);
  
  if(read_r_old == 0 && read_r == 1){
    if(state_r == 0){
      analogWrite(out_r, 100);
    }else{
      analogWrite(out_r, 0);
    }
    state_r = !state_r;
  }
  if(read_g_old == 0 && read_g == 1){
    if(state_g == 0){
      analogWrite(out_g, 47);
    }else{
      analogWrite(out_g, 0);
    }
    state_g = !state_g;
  }
  if(read_b_old == 0 && read_b == 1){
    if(state_b == 0){
      analogWrite(out_b, 35);
    }else{
      analogWrite(out_b, 0);
    }
    state_b = !state_b;
  }
  read_r_old = read_r;
  read_g_old = read_g;
  read_b_old = read_b;
  delay(delayTime);
}