#include <stdio.h>

// 배열에서 최솟값 반환
int find_min(int arr[], int n) {
  int min = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

int main() {
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("min = %d\n", find_min(arr, n));
  return 0;
}