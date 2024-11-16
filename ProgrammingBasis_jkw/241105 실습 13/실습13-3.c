#include <stdio.h>
#include <string.h>

static char name[3][10] = {"empty", "empty", "empty"};
static int score_number[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
static char score_char[3][3] = {
    {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

int FindMaxScoreAt(char *subject) {
  int max = 0;
  int find_index = 0;
  if (strcmp(subject, "korean") == 0) {
    find_index = 0;
  } else if (strcmp(subject, "english") == 0) {
    find_index = 1;
  } else if (strcmp(subject, "math") == 0) {
    find_index = 2;
  }

  for (int i = 0; i < 3; i++) {
    if (score_number[i][find_index] > max) {
      max = score_number[i][find_index];
    }
  }

  return max;
}

void updateScore() {
  int max_korean = FindMaxScoreAt("korean");
  int max_english = FindMaxScoreAt("english");
  int max_math = FindMaxScoreAt("math");

  for (int i = 0; i < 3; i++) {
    if (score_number[i][0] == max_korean) {
      score_char[i][0] = 'A';
    } else {
      score_char[i][0] = '-';
    }

    if (score_number[i][1] == max_english) {
      score_char[i][1] = 'A';
    } else {
      score_char[i][1] = '-';
    }

    if (score_number[i][2] == max_math) {
      score_char[i][2] = 'A';
    } else {
      score_char[i][2] = '-';
    }
  }
}

int main() {
  // 이름/국어점수/영어점수/수학점수 입력 받기
  for (int i = 0; i < 3; i++) {
    scanf("%s %d %d %d", &name[i], &score_number[i][0], &score_number[i][1],
          &score_number[i][2]);
    updateScore();
  }

  for (int i = 0; i < 3; i++) {
    printf("%s %d(%c) %d(%c) %d(%c)\n", name[i], score_number[i][0],
           score_char[i][0], score_number[i][1], score_char[i][1],
           score_number[i][2], score_char[i][2]);
  }

  return 0;
}