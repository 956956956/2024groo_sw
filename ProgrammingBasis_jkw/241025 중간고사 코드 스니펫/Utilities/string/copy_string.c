#include <stdio.h>
#include <string.h>

// ����� ������ ��
// 1. ������ ���ڿ��� ���̰� ���������� ��� �����÷ο� �߻�
// 2. ������ ���ڿ��� ���̰� ���������� ª���� NULL ���ڰ� ������� �ʾ�
// ���ڿ��� ���� (�Ǵ� ���α׷� ����)
// 3. ������ ���ڿ��� ���̰� �������� ������ NULL ���ڰ� ������� �ʾ� ���ڿ���
// ���� (�Ǵ� ���α׷� ����)

// string.h �Ἥ ����
void copyString(char* dest, char* src) {
  // src�� dest�� ����
  strcpy(dest, src);
}

// string.h �Ⱦ��� ����
void copyStringWithWhile(char* dest, char* src) {
  // src�� dest�� ����
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