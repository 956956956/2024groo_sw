#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  char *name, *subject, *score_str;
  int total_score = 0, count = 0;

  while (1) {
    fgets(input, sizeof(input), stdin);

    if (strncmp(input, "quit", 4) == 0) {
      break;
    }

    name = strtok(input, ",");
    subject = strtok(NULL, ",");
    score_str = strtok(NULL, ",");

    while (*subject == ' ') subject++;
    while (*score_str == ' ') score_str++;

    int score = atoi(score_str);

    printf("%s\t%s\t%d\n", name, subject, score);

    total_score += score;
    count++;
  }

  double average = (double)total_score / count;
  printf("avg=%.1f\n", average);

  return 0;
}
