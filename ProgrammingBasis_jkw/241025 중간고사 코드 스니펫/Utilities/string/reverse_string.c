#include <stdio.h>
#include <string.h>

// ���ڿ��� ���� ��ü�� ��ä�� ������
void reverseString(char* str) {
  int length = strlen(str);
  for (int i = 0; i < length / 2; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
}

// string.h �Ⱦ��� ������
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