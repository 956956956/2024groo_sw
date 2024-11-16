#include <math.h>
#include <stdio.h>

int lcm(int x, int y) {
  if (x == 1 || y == 1) return x * y;
  if (x == y) return x;

  int i = fmax(x, y);
  for (i; i <= x * y; i++) {
    if (i % x == 0 && i % y == 0) {
      return i;
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  printf("%d", lcm(n, m));

  return 0;
}
