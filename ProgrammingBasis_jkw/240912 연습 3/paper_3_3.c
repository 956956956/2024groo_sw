#define MYSTR1 "2024005056"
#define MYSTR2 "����"

#include <stdio.h>

int main() {
  printf("�й� = \"%-15s\"\n", MYSTR1);
  printf("�̸� = \"%15s\"", MYSTR2);
  return 0;
}