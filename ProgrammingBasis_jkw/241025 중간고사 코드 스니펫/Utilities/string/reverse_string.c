#include <stdio.h>
#include <string.h>

// 문자열의 원본 자체를 통채로 뒤집음
void reverseString(char* str) {
  int length = strlen(str);
  for (int i = 0; i < length / 2; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
}

// string.h 안쓰고 뒤집기
void reverseStringWithWhile(char* str) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  for (int i = 0; i < length / 2; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
}

int main() {
  char str[] = "Hello, World!";
  reverseString(str);
  printf("%s\n", str);
  return 0;
}