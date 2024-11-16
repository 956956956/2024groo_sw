#include <stdio.h>

void findSum(int data[], int n, int *sum) {
  for (int i = 0; i < n; i++) {
    *sum += data[i];
  }
}

int main() {
  // 정수 입력
  int n;
  scanf("%d", &n);

  // 정수개의 원소를 포함하는 배열
  int array[1000] = {0};
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // 출력
  int result = 0;
  findSum(array, n, &result);  // (배열시작점Address, 갯수, 결과Address)

  printf("%d", result);

  return 0;
}