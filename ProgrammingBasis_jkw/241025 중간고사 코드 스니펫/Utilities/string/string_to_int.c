#include <stdio.h>
#include <stdlib.h>

// stdlib.h로 문자열을 정수로 변환
int stringToInt(char* str) { return atoi(str); }

int main() {
  char str[10] = "123";
  int num = stringToInt(str);
  printf("%d\n", num);
  return 0;
}