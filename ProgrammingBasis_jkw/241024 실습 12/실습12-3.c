#include <stdio.h>
#include <string.h>

int main() {
  int matrix[4][4] = {};

  // ��� �Է��� ������ ��ġ�� ����
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &matrix[j][i]);
    }
  }

  // ���
  for (int i = 0; i < 4; i++) {
    for (int ii = 0; ii < 4; ii++) {
      printf("%4d", matrix[i][ii]);
    }
    printf("\n");
  }

  return 0;
}