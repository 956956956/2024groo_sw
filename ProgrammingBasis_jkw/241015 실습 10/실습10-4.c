#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char str[3][1000];

  gets(str[0]);
  gets(str[1]);
  gets(str[2]);

  int count = 0;
  char result[10000] = {};

  for (int i = 0; i < 3; i++) {
    for (int ii = 0; ii < strlen(str[i]); ii++) {
      if (ispunct(str[i][ii])) {
        result[count] = str[i][ii];
        count++;
      }
    }
  }

  printf("%d %s", count, result);

  return 0;
}