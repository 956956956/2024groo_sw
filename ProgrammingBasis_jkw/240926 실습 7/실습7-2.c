#include <stdio.h>

int main() {
  double arr[100000] = {};

  int count = 0;
  while (1) {
    double n;
    scanf("%lf", &n);
    if (n == 0) {
      break;
    }
    arr[count] = n;
    count++;
  }

  double sum = 0;
  for (int i = 0; i < count; i++) {
    sum += arr[i];
  }
  double avg = sum / count;

  printf("%.1lf\n", avg);
  for (int i = 0; i < count; i++) {
    if (arr[i] < avg) {
      printf("%.1lf ", arr[i]);
    }
  }

  return 0;
}