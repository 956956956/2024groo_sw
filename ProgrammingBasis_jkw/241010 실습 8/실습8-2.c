#include <stdio.h>

void printStar(int n) {
  int story = 1;

  for (story; story <= n; story++) {
    for (int i = 0; i < n - story; i++) {
      printf(" ");
    }
    for (int i = 0; i < story - 1; i++) {
      printf("*");
    }

    // ¼¾ÅÍº°
    printf("*");

    for (int i = 0; i < story - 1; i++) {
      printf("*");
    }
    printf("\n");
  }
}

int main() {
  int n;
  scanf("%d", &n);

  printStar(n);

  return 0;
}