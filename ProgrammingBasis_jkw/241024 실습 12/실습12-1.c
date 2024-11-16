#include <stdio.h>
#include <string.h>

char encryptChar(char c, const char table[1000][1000]) {
  for (int i = 0; i < strlen(table[0]); i++) {
    if (table[0][i] == c) {
      return table[1][i];
    }
  }
  return c;
}

int main() {
  char table[2][1000] = {
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ",  // Å¸°Ù
      "hknopijxyzqfgmvwulastbcrde"   // º¯È¯ ÈÄ
  };

  char raw[1000] = {};
  gets(raw);

  for (int i = 0; i < strlen(raw); i++) {
    if (raw[i] == ' ') {
      printf(" ");
    } else {
      printf("%c", encryptChar(raw[i], table));
    }
  }

  return 0;
}