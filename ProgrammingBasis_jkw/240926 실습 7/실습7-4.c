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

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < count; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}