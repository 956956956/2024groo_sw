#include <stdio.h>

int main() {
  for (int b = 1; b <= 9; b++) {
    for (int a = 1; a <= 5; a++) {
      if (a >= 5) {
        printf("%d*%d=%d", a, b, b * a);

      } else {
        printf("%d*%d=%d\t\t", a, b, b * a);
      }
    }
    printf("\n");
  }
  return 0;
}