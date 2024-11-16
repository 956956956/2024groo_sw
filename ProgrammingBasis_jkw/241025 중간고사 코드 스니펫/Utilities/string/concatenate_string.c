#include <stdio.h>
#include <string.h>

// string.h 써서 연결
void concatenateString(char* dest, char* src) {
  // src를 dest에 연결
  strcat(dest, src);
}

// string.h 안쓰고 연결
void concatenateStringWithWhile(char* dest, char* src) {
  // src를 dest에 연결
  while (*dest != '\0') {
    dest++;
  }
  while (*src != '\0') {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = '\0';
}

int main() {
  char str1[10] = "Hello";
  char str2[10] = "World";

  // 주의할 점
  // 1. 연결할 문자열의 길이가 목적지보다 길면 오버플로우 발생
  // 2. 연결할 문자열의 길이가 목적지보다 짧으면 NULL 문자가 복사되지 않아
  // 문자열이 깨짐 (또는 프로그램 터짐)
  // 3. 연결할 문자열의 길이가 목적지와 같으면 NULL 문자가 복사되지 않아
  // 문자열이 깨짐 (또는 프로그램 터짐)
  concatenateString(str1, str2);
  printf("%s\n", str1);
  return 0;
}