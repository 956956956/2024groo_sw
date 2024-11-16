#include <stdio.h>

/* swap 사용 예시
    int x = 5;
    int y = 10;
    swap(&x, &y)
*/

// 주소로 받아서 값을 서로 바꿈
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