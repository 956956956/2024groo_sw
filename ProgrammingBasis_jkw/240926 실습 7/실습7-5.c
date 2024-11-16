#include <stdio.h>

int main() {
  int arr[100000] = {};

  int count = 0;
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    arr[count] = n;
    count++;
  }

  int min = arr[0];
  int max = arr[0];

  for (int i = 0; i < count; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  printf("%d %d", max, min);

  return 0;
}