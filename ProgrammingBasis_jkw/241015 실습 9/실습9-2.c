#include <stdio.h>

char scoreToGrade(int score) {
  if (score >= 90) {
    return 'A';
  } else if (score >= 80) {
    return 'B';
  } else if (score >= 70) {
    return 'C';
  } else if (score >= 60) {
    return 'D';
  } else {
    return 'F';
  }
}

int main() {
  while (1) {
    int score;
    scanf("%d", &score);
    if (score == -1) {
      return 0;
    }
    printf("%c\n", scoreToGrade(score));
  }
  return 0;
}