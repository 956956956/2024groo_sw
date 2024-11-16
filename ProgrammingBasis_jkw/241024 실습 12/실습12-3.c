#include <stdio.h>
#include <string.h>

int main() {
  int matrix[4][4] = {};

  // 행렬 입력할 때부터 전치로 대입
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &matrix[j][i]);
    }
  }

  // 출력
  for (int i = 0; i < 4; i++) {
    for (int ii = 0; ii < 4; ii++) {
      printf("%4d", matrix[i][ii]);
    }
    printf("\n");
  }

  return 0;
}