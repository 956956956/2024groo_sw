#include <stdio.h>
#include <string.h>

// string.h�� ���ϴ� �Լ�
int compareString(char *str1, char *str2) { return strcmp(str1, str2); }

// string.h �Ⱦ��� ��
int compareStringWithWhile(char *str1, char *str2) {
  int i = 0;

  // �� ���ڿ��� ������ Ȯ��
  // 1. ���ڿ��� ���ٸ� 0�� ��ȯ
  // 2. ù ��° ���ڿ��� �� ��° ���ڿ����� ũ�ٸ� ���(+)�� ��ȯ
  // 3. ù ��° ���ڿ��� �� ��° ���ڿ����� �۴ٸ� ����(-)�� ��ȯ
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

  // �� ���ڿ��� ������ Ȯ��
  // 1. ���ڿ��� ���ٸ� 0�� ��ȯ
  // 2. ù ��° ���ڿ��� �� ��° ���ڿ����� ũ�ٸ� ���(+)�� ��ȯ
  // 3. ù ��° ���ڿ��� �� ��° ���ڿ����� �۴ٸ� ����(-)�� ��ȯ

  // ���������� �� ���ڿ��� ���ؼ� ���/���� ��ȯ�Ǵ°���.
  // ù��° ���ڿ��� �ι�° ���ڿ����� ���������� ���� ���ĵǸ� ���� ��ȯ
  // ù��° ���ڿ��� �ι�° ���ڿ����� ���������� ���߿� ���ĵǸ� ��� ��ȯ
  compare = compareString(str1, str2);

  if (compare == 0)
    printf("[%d] Both strings are equal.\n", compare);
  else if (compare > 0)
    printf("[%d] First string is greater than second.\n", compare);
  else
    printf("[%d] First string is less than second.\n", compare);

  return 0;
}