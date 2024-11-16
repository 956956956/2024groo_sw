#include <stdio.h>
#include <string.h>

int isSameMatrix(const int a[3][3], const int b[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // 중간에 하나라도 다르면 0(False) 반환
      if (a[i][j] != b[i][j]) {
        return 0;
      }
    }
  }
  // 모두 같으면 1(True) 반환
  return 1;
}

int main() {
  int matrix[2][3][3] = {0};

  // 행렬 2개 입력
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        scanf("%d", &matrix[i][j][k]);
      }
    }
  }

  // 출력
  if (isSameMatrix(matrix[0], matrix[1])) {
    printf("same");
  } else {
    printf("not same");
  }

  return 0;
}