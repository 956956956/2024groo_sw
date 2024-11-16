#include <stdio.h>

int main() {
  float sum = 0.0f;
  int count = 0;

  while (1) {
    int a;
    scanf("%d", &a);
    if (a < 0) {
      break;
    }
    sum += a;
    count++;
  }

  printf("%.2f", sum / count);
  return 0;
}