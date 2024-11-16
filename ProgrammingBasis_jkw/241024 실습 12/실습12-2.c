#include <stdio.h>
#include <string.h>

int ArraySum(const int arry[], int size) {
  int result = 0;

  for (int i = 0; i < size; i++) {
    result += arry[i];
  }

  return result;
}

int ArrayFindMin(const int arry[], int size) {
  int min = arry[0];

  for (int i = 0; i < size; i++) {
    if (arry[i] < min) {
      min = arry[i];
    }
  }

  return min;
}

int main() {
  int array_size;
  scanf("%d", &array_size);

  int array_size_copy = array_size;

  int result = 0;
  int min = 1000000;

  while (array_size > 0) {
    int array[100] = {};
    for (int i = 0; i < array_size_copy; i++) {
      scanf("%d", &array[i]);
    }

    result += ArraySum(array, array_size_copy);
    int new_min = ArrayFindMin(array, array_size_copy);

    if (new_min < min) {
      min = new_min;
    }

    array_size -= 1;
  }

  printf("%d %d", result, min);

  return 0;
}