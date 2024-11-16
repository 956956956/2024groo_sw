#include <stdio.h>
#include <string.h>

int main() {
  char sentence[100] = {};
  int frequency[52] = {};

  gets(sentence);

  for (int i = 0; i < strlen(sentence); i++) {
    if ('A' <= sentence[i] && sentence[i] <= 'Z') {
      frequency[sentence[i] - 'A']++;
    } else if ('a' <= sentence[i] && sentence[i] <= 'z') {
      frequency[sentence[i] - 'a' + 26]++;
    }
  }

  for (int i = 0; i < 52; i++) {
    if (frequency[i] <= 0) continue;
    if (i < 26) {
      printf("%c:%d\n", 'A' + i, frequency[i]);
    } else {
      printf("%c:%d\n", 'a' + i - 26, frequency[i]);
    }
  }
}