#include <stdio.h>
#include <string.h>

int main() {
  int matrix[5][5] = {0};

  // ��� �Է� �����鼭 ������ �ε����� �� ����
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &matrix[i][j]);
      matrix[4][j] += matrix[i][j];  // ���� ��
      matrix[i][4] += matrix[i][j];  // ���� ��
      matrix[4][4] += matrix[i][j];  // ��ü ��
    }
  }

  // ���
  for (int i = 0; i < 5; i++) {
    for (int ii = 0; ii < 5; ii++) {
      printf("%4d", matrix[i][ii]);
    }
    printf("\n");
  }

  return 0;
}