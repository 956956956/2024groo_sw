#include <stdio.h>

int main() {
  int a = 5, b = 10, c = 15, d = 20;

  printf("%d\n", a + ++b);
  printf("%d\n", a && 0);
  printf("%d\n", a + b + c % a);
  printf("%d\n", --c / b);
  printf("%d\n", d - c--);
  printf("%d\n", a % 4 + b + d / b++);
  printf("%d\n", d - a + c % 8);
}