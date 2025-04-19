int br = 115200;
int time_com = 200;

float grade_array[10];
int grade_num;
int i;

float grade_sum;
float grade_avg;
float grade_max;
float grade_min;

void setup() {
  Serial.begin(br);
}

void loop() {
  Serial.println("Input anything to start program...");
  while (Serial.available() == 0) { delay(time_com); }
  Serial.parseInt();
  Serial.println("How many grades you want input...");
  while (Serial.available() == 0) { delay(time_com); }
  grade_num = Serial.parseInt();
  while (i < grade_num) {
    Serial.println("Input your grade " + String(i + 1));
    while (Serial.available() == 0) { delay(time_com); }
    grade_array[i] = Serial.parseFloat();
    grade_sum = grade_sum + grade_array[i];
    if (i == 0) {
      grade_max = grade_array[i];
      grade_min = grade_array[i];
    } else {
      if (grade_array[i - 1] < grade_array[i]) {
        grade_max = grade_array[i];
      } else {
        grade_min = grade_array[i];
      }
    }
    i = i + 1;
  }
  i = 0;
  Serial.println("-----------------------------");
  while (i < grade_num) {
    Serial.println("|Your grade " + String(i + 1) + " is        " + String(grade_array[i]) + "|");
    //reset
    grade_array[i] = 0;
    i = i + 1;
  }
  i = 0;
  Serial.println("|---------------------------|");
  grade_avg = grade_sum / grade_num;
  Serial.println("|Your highest grade is  " + String(grade_max) + "|");
  Serial.println("|Your lowest  grade is  " + String(grade_min) + "|");
  Serial.println("|Your average grade is  " + String(grade_avg) + "|");
  Serial.println("-----------------------------");
  //reset
  grade_sum = 0;
}
