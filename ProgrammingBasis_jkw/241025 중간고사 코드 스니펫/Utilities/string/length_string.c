#include <stdio.h>
#include <string.h>

// string.h 안쓰는 함수
int length_string(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

// string.h 쓰는 함수
int length_string(char *str) {
  // 그냥 strlen 바로 써도 됨
  return strlen(str);
}

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);
  printf("Length of the string: %d\n", length_string(str));
  return 0;
}