#include <stdio.h>

void findSum(int data[], int n, int *sum) {
  for (int i = 0; i < n; i++) {
    *sum += data[i];
  }
}

int main() {
  // ���� �Է�
  int n;
  scanf("%d", &n);

  // �������� ���Ҹ� �����ϴ� �迭
  int array[1000] = {0};
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // ���
  int result = 0;
  findSum(array, n, &result);  // (�迭������Address, ����, ���Address)

  printf("%d", result);

  return 0;
}