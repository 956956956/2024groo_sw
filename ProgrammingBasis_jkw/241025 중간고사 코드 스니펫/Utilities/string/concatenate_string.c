#include <stdio.h>
#include <string.h>

// string.h �Ἥ ����
void concatenateString(char* dest, char* src) {
  // src�� dest�� ����
  strcat(dest, src);
}

// string.h �Ⱦ��� ����
void concatenateStringWithWhile(char* dest, char* src) {
  // src�� dest�� ����
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

  // ������ ��
  // 1. ������ ���ڿ��� ���̰� ���������� ��� �����÷ο� �߻�
  // 2. ������ ���ڿ��� ���̰� ���������� ª���� NULL ���ڰ� ������� �ʾ�
  // ���ڿ��� ���� (�Ǵ� ���α׷� ����)
  // 3. ������ ���ڿ��� ���̰� �������� ������ NULL ���ڰ� ������� �ʾ�
  // ���ڿ��� ���� (�Ǵ� ���α׷� ����)
  concatenateString(str1, str2);
  printf("%s\n", str1);
  return 0;
}