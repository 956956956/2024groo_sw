#include <stdio.h>

/* swap ��� ����
    int x = 5;
    int y = 10;
    swap(&x, &y)
*/

// �ּҷ� �޾Ƽ� ���� ���� �ٲ�
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int x = 5;
  int y = 10;
  printf("x: %d, y: %d\n", x, y);
  swap(&x, &y);
  printf("x: %d, y: %d\n", x, y);
  return 0;
}