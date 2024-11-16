#include <stdio.h>
#include <string.h>

int main() {
  int matrix[5][5] = {0};

  // 행렬 입력 받으면서 마지막 인덱스에 합 저장
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &matrix[i][j]);
      matrix[4][j] += matrix[i][j];  // 열의 합
      matrix[i][4] += matrix[i][j];  // 행의 합
      matrix[4][4] += matrix[i][j];  // 전체 합
    }
  }

  // 출력
  for (int i = 0; i < 5; i++) {
    for (int ii = 0; ii < 5; ii++) {
      printf("%4d", matrix[i][ii]);
    }
    printf("\n");
  }

  return 0;
}