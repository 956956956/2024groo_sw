#include <stdio.h>

int GCD(int a, int b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}

int main() {
  int a, b;
  while (1) {
    scanf("%d %d", &a, &b);
    if (a == 0 && b == 0) break;
    printf("%d\n", GCD(a, b));
  }
  return 0;
}