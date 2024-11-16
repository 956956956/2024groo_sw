#include <stdio.h>

int accumulateSum(int num) {
  static int sum = 0;
  sum += num;
  return sum;
}

int main() {
  int value, sum;
  while (1) {
    scanf("%d", &value);
    if (value < 0) break;
    sum = accumulateSum(value);
    printf("value : %d, sum : %d\n", value, sum);
  }
  printf("Total sum : %d\n", accumulateSum(0));
  return 0;
}