#include <stdio.h>
#include <string.h>

// string.h �Ⱦ��� �Լ�
int length_string(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

// string.h ���� �Լ�
int length_string(char *str) {
  // �׳� strlen �ٷ� �ᵵ ��
  return strlen(str);
}

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);
  printf("Length of the string: %d\n", length_string(str));
  return 0;
}