#include <stdio.h>

// 퀵 정렬을 위한 함수
void quickSort(int arr[], int left, int right) {
  if (left >= right) return;

  int pivot = arr[(left + right) / 2];
  int low = left;
  int high = right;

  while (low <= high) {
    while (arr[low] < pivot) low++;
    while (arr[high] > pivot) high--;

    if (low <= high) {
      int temp = arr[low];
      arr[low] = arr[high];
      arr[high] = temp;
      low++;
      high--;
    }
  }

  quickSort(arr, left, high);
  quickSort(arr, low, right);
}

int main() {
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}