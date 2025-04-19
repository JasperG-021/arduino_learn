int br = 115200;
int time_com = 200;

float grade_array[10];

int grade_num;
int i;
int j;

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
    } else {//there is a bug in last version
      if (grade_max < grade_array[i]) {
        grade_max = grade_array[i];
      }
      if (grade_array[i] < grade_min) {
        grade_min = grade_array[i];
      }
    }
    i++;
  }
  i = 0;
  //print result
  Serial.println("-----------------------------");
  grade_avg = grade_sum / grade_num;
  Serial.println("|Your highest grade is  " + String(grade_max) + "|");
  Serial.println("|Your lowest  grade is  " + String(grade_min) + "|");
  Serial.println("|Your average grade is  " + String(grade_avg) + "|");
  Serial.println("|---------------------------|");
  //reset grade_sum
  grade_sum = 0;
  //sort
  while (j < grade_num) {
    //print sorted result, already know the hightest grade
    Serial.println("|Your rank " + String(j + 1) + " grade is   " + String(grade_max)+ "|");
    //delete one of the hightest grade in grade_array, for get the second hightest grade.
    while (i < grade_num) {
      if (grade_array[i] == grade_max) {
        //reset grade_array
        //may have same grade, just delete one of them
        grade_array[i] = 0;
        break;
      }
      i++;
    }
    i = 0;
    //reset grade_max, get the second hightest grade
    grade_max = 0;
    while (i < 4) {
      if (grade_max < grade_array[i]) {
        grade_max = grade_array[i];
      }
      i++;
    }
    i = 0;
    j++;
  }
  j = 0;
  Serial.println("-----------------------------");
}
