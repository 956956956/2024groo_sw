#include <stdio.h>

// 선택 정렬을 위한 함수
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

int main() {
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}