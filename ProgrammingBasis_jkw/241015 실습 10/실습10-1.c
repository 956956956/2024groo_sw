#include <stdio.h>
#include <string.h>

int main() {
  // ����� "�� ������ �Է� �ޱ�
  char str[100];
  gets(str);

  char *ptr = strtok(str, " ");
  while (ptr != NULL) {
    for (int i = strlen(ptr) - 1; i >= 0; i--) {
      printf("%c", ptr[i]);
    }
    printf(" ");
    ptr = strtok(NULL, " ");
  }
}