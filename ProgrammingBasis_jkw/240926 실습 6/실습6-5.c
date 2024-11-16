#include <stdio.h>
#define TRUE 1

int main() {
  int a;
  int b;
  char operator;

  while (TRUE) {
    scanf("%d%c%d", &a, &operator, & b);
    if (operator== '!') {
      break;
    }

    if (operator== '+') {
      printf("%d+%d=%d\n", a, b, a + b);
    } else if (operator== '-') {
      printf("%d-%d=%d\n", a, b, a - b);
    } else if (operator== '*') {
      printf("%d*%d=%d\n", a, b, a * b);
    } else if (operator== '/') {
      if (b == 0) {
        printf("Error\n");
      } else {
        printf("%d/%d=%.2f\n", a, b, (float)a / b);
      }
    }
  }
  return 0;
}