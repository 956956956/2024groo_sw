#include <ctype.h>
#include <stdio.h>

// 문자열을 대문자로 변환
void toUpperCase(char* str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = toupper(str[i]);
  }
}

// 문자열을 소문자로 변환
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