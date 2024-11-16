#include <stdio.h>

void mySwap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(int argc, char *argv[]) {
  int x, y;
  scanf("%d %d", &x, &y);

  mySwap(&x, &y);
  printf("%d %d\n", x, y);

  return 0;
}