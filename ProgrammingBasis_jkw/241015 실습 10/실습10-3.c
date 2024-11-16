#include <stdio.h>
#include <string.h>

int main() {
  while (1) {
    char pass1[100];
    char pass2[100];

    gets(pass1);
    // 1-1. pass1 길이 확인
    if ((strlen(pass1) < 5 || strlen(pass1) > 10)) {
      printf("Retry\n");
      continue;
    }

    gets(pass2);
    // 1-2. pass2 길이 확인
    if ((strlen(pass2) < 5 || strlen(pass2) > 10)) {
      printf("Retry\n");
      continue;
    }

    if (strcmp(pass1, pass2) != 0) {
      printf("Retry\n");
      continue;
    }

    printf("Done");
    return 0;
  }
}