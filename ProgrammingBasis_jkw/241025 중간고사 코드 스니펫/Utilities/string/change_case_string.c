#include <ctype.h>
#include <stdio.h>

// ���ڿ��� �빮�ڷ� ��ȯ
void toUpperCase(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = toupper(str[i]);
  }
}

// ���ڿ��� �ҹ��ڷ� ��ȯ
void toLowerCase(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = tolower(str[i]);
  }
}

int main() {
  char str[] = "Hello, World!";
  toUpperCase(str);
  printf("%s\n", str);  // HELLO, WORLD!

  toLowerCase(str);
  printf("%s\n", str);  // hello, world!

  return 0;
}