#define MYSTR1 "2024005056"
#define MYSTR2 "장기원"

#include <stdio.h>

int main() {
  printf("학번 = \"%-15s\"\n", MYSTR1);
  printf("이름 = \"%15s\"", MYSTR2);
  return 0;
}