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
  // ����
  int n;
  scanf("%d", &n);

  // �迭 �Է�
  int array[1000] = {0};
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // �ִ�/�ּ� ����
  int min = array[0], max = 0;

  // (�迭������Address, ����, �ּ�Address, �ִ�Address)
  minMax(array, n, &min, &max);

  printf("%d %d", max, min);

  return 0;
}