#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

void sortWithoutDuplication(int arry[], int *size) {
  // 정렬 First
  for (int i = 0; i < *size; i++) {
    for (int j = i + 1; j < *size; j++) {
      if (arry[i] > arry[j]) {
        swap(&arry[i], &arry[j]);
      }
    }
  }

  // 중복 제거
  for (int i = 0; i < *size - 1; i++) {
    if (arry[i] == arry[i + 1]) {
      for (int j = i; j < *size - 1; j++) {
        arry[j] = arry[j + 1];
      }
      *size -= 1;
      i -= 1;
    }
  }
  return;
}

int main() {
  // 10개 배열 입력
  int array[10] = {0};
  for (int i = 0; i < 10; i++) {
    scanf("%d", &array[i]);
  }

  int size = 10;
  sortWithoutDuplication(array, &size);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}