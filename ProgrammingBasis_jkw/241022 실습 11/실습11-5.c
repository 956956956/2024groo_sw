#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char word[100][100];

  // quit 입력 전까지 word에 저장
  int i = 0;
  while (1) {
    char input[100] = {};
    scanf("%s", input);

    if (strncmp(input, "quit", 4) == 0) {
      break;
    } else {
      strcpy(word[i], input);
    }

    i++;
  }

  // word를 사전순으로 저장
  for (int j = 0; j < i; j++) {
    for (int k = j + 1; k < i; k++) {
      if (strcmp(word[j], word[k]) > 0) {
        char temp[100];
        strcpy(temp, word[j]);
        strcpy(word[j], word[k]);
        strcpy(word[k], temp);
      }
    }
  }

  // 출력
  for (int j = 0; j < i; j++) {
    printf("%s\n", word[j]);
  }

  return 0;
}
