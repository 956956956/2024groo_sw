#include <stdio.h>
#include <string.h>

// string.h로 비교하는 함수
int compareString(char *str1, char *str2) { return strcmp(str1, str2); }

// string.h 안쓰고 비교
int compareStringWithWhile(char *str1, char *str2) {
  int i = 0;

  // 두 문자열이 같은지 확인
  // 1. 문자열이 같다면 0을 반환
  // 2. 첫 번째 문자열이 두 번째 문자열보다 크다면 양수(+)를 반환
  // 3. 첫 번째 문자열이 두 번째 문자열보다 작다면 음수(-)를 반환
  while (str1[i] == str2[i]) {
    if (str1[i] == '\0' || str2[i] == '\0') break;
    i++;
  }

  if (str1[i] == '\0' && str2[i] == '\0')
    return 0;
  else
    return str1[i] - str2[i];
}

int main() {
  char str1[100], str2[100];
  int compare;

  printf("Enter first string: ");
  gets(str1);

  printf("Enter second string: ");
  gets(str2);

  // 두 문자열이 같은지 확인
  // 1. 문자열이 같다면 0을 반환
  // 2. 첫 번째 문자열이 두 번째 문자열보다 크다면 양수(+)를 반환
  // 3. 첫 번째 문자열이 두 번째 문자열보다 작다면 음수(-)를 반환

  // 사전적으로 두 문자열을 비교해서 양수/음수 반환되는거임.
  // 첫번째 문자열이 두번째 문자열보다 사전적으로 먼저 정렬되면 음수 반환
  // 첫번째 문자열이 두번째 문자열보다 사전적으로 나중에 정렬되면 양수 반환
  compare = compareString(str1, str2);

  if (compare == 0)
    printf("[%d] Both strings are equal.\n", compare);
  else if (compare > 0)
    printf("[%d] First string is greater than second.\n", compare);
  else
    printf("[%d] First string is less than second.\n", compare);

  return 0;
}