#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int ii = 1; ii <= i+1; ii++) {
      printf("%d", ii);
    }
    for (int iii = 1; iii < n - i; iii++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}