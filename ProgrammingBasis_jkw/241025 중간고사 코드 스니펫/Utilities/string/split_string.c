#include <stdio.h>
#include <string.h>

// ���ڿ� ��ūȭ�ؼ� ������ ����
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