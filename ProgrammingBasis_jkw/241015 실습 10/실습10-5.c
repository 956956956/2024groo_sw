#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  int count = 0;
  char longest_word[1000] = {};

  char input[3][1000];
  char delimiter[] = " .,!\t\n\r";

  char *ptoken;

  for (int i = 0; i < 3; i++) {
    gets(input[i]);
    char *ptoken = strtok(input[i], delimiter);
    while (ptoken != NULL) {
      count++;

      if (strlen(ptoken) > strlen(longest_word)) {
        strcpy(longest_word, ptoken);
      }

      ptoken = strtok(NULL, delimiter);
    }
  }

  printf("%d %s", count, longest_word);

  return 0;
}