float grade_array[10];

int grade_num;
int i;

float grade_sum;
float grade_max;
float grade_min;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("Input anything to start program...");
  wait();
  Serial.parseInt();
  grade_input();
  sort_bubble();
  grade_print();
}

void wait() {
  int time_com = 200;
  while (Serial.available() == 0) { delay(time_com); }
}

void grade_input() {
  Serial.println("How many grades you want input...");
  wait();
  grade_num = Serial.parseInt();
  while (i < grade_num) {
    Serial.println("Input your grade " + String(i + 1));
    wait();
    grade_array[i] = Serial.parseFloat();
    grade_sum = grade_sum + grade_array[i];
    if (i == 0) {
      grade_max = grade_array[i];
      grade_min = grade_array[i];
    } else {  //there is a bug in last version
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
}

void sort_bubble() {
  int flage = 1;
  float grade_temp;

  while (flage == 1) {
    flage = 0;
    while (i < grade_num - 1) {
      if (grade_array[i] < grade_array[i + 1]) {
        grade_temp = grade_array[i];
        grade_array[i] = grade_array[i + 1];
        grade_array[i + 1] = grade_temp;
        flage = 1;
      }
      i++;
    }
    i = 0;
  }
}

void grade_print() {
  float grade_avg;
  Serial.println("-----------------------------");
  while (i < grade_num) {
    Serial.println("|Your rank " + String(i + 1) + " grade is   " + String(grade_array[i]) + "|");
    i++;
  }
  i = 0;
  Serial.println("|---------------------------|");

  grade_avg = grade_sum / grade_num;
  Serial.println("|Your highest grade is  " + String(grade_max) + "|");
  Serial.println("|Your lowest  grade is  " + String(grade_min) + "|");
  Serial.println("|Your average grade is  " + String(grade_avg) + "|");
  Serial.println("-----------------------------");
}