#include <stdio.h>

// 배열에서 최댓값 반환
int find_max(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("max = %d\n", find_max(arr, n));
  return 0;
}