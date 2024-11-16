#include <stdio.h>
#include <string.h>

int main() {
  for (int i = 0; i < 4; i++) {
    char name[100] = {};
    int score[3] = {0};

    scanf("%s %d %d %d\n", name, &score[0], &score[1], &score[2]);
    printf("%s %d %d %d %d\n", name, score[0], score[1], score[2],
           score[0] + score[1] + score[2]);
  }

  return 0;
}