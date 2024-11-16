#include <stdio.h>

void print1DArray(int *d, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", *(d + i));
  }
  printf("\n");
  return;
}

int main(int argc, char *argv[]) {
  // ���� ����
  int count;
  scanf("%d", &count);

  // �迭 �Է�
  int array[1000] = {0};
  for (int i = 0; i < count; i++) {
    scanf("%d", &array[i]);
  }

  // ������ �̵��ϸ鼭 ���
  int *p = array;
  for (int i = 0; i < count; i++) {
    print1DArray(p, count - i);  // (������, ��� ����)
    p++;                         // ������ �̵�
  }

  return 0;
}