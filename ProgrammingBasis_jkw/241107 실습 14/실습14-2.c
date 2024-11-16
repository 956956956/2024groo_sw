#include <stdio.h>

int printReverse(int n) {
  if (n == 0) return 0;
  printf("%d", n % 10);
  return printReverse(n / 10);
}

int main() {
  int n;
  scanf("%d", &n);

  printReverse(n);

  return 0;
}