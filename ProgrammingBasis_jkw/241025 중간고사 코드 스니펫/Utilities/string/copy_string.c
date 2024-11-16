#include <stdio.h>
#include <string.h>

// 복사시 주의할 점
// 1. 복사할 문자열의 길이가 목적지보다 길면 오버플로우 발생
// 2. 복사할 문자열의 길이가 목적지보다 짧으면 NULL 문자가 복사되지 않아
// 문자열이 깨짐 (또는 프로그램 터짐)
// 3. 복사할 문자열의 길이가 목적지와 같으면 NULL 문자가 복사되지 않아 문자열이
// 깨짐 (또는 프로그램 터짐)

// string.h 써서 복사
void copyString(char* dest, char* src) {
  // src를 dest로 복사
  strcpy(dest, src);
}

// string.h 안쓰고 복사
void copyStringWithWhile(char* dest, char* src) {
  // src를 dest로 복사
  while (*src != '\0') {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = '\0';
}

int main() {
  char str1[10] = "Hello";
  char str2[10];
  copyString(str2, str1);
  printf("%s\n", str2);
  return 0;
}