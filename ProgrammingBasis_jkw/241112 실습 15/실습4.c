#include <stdio.h>

void minMax(int data[], int n, int *min, int *max) {
  for (int i = 0; i < n; i++) {
    if (data[i] < *min) {
      *min = data[i];
    }
    if (data[i] > *max) {
      *max = data[i];
    }
  }
}

int main() {
  // 정수
  int n;
  scanf("%d", &n);

  // 배열 입력
  int array[1000] = {0};
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // 최대/최소 저장
  int min = array[0], max = 0;

  // (배열시작점Address, 갯수, 최소Address, 최대Address)
  minMax(array, n, &min, &max);

  printf("%d %d", max, min);

  return 0;
}