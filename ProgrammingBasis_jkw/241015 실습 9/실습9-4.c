#include <stdio.h>

int checkLastDigit(int arr[], int size, int num) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 10 == num) {
      count++;
    }
  }
  return count;
}

int main() {
  int arr[100000] = {0};
  int size;
  scanf("%d", &size);

  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < 10; i++) {
    printf("%d %d\n", i, checkLastDigit(arr, size, i));
  }
}