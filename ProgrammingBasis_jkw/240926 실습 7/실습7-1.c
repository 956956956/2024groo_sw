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

  printf("%d\n", count);
  for (int i = count - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  return 0;
}