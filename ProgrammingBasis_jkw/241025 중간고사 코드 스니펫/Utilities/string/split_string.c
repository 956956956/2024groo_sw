#include <stdio.h>
#include <string.h>

// 문자열 토큰화해서 나누는 예시
void tokenizeString(char* str, const char* delimiter) {
  char* token = strtok(str, delimiter);
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, delimiter);
  }
}

int main() {
  char str[] = "apple,banana,grape";
  tokenizeString(str, ",");
  return 0;
}