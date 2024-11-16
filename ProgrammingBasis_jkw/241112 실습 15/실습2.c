#include <stdio.h>

void print1DArray(int *d, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", *(d + i));
  }
  printf("\n");
  return;
}

int main(int argc, char *argv[]) {
  // 정수 갯수
  int count;
  scanf("%d", &count);

  // 배열 입력
  int array[1000] = {0};
  for (int i = 0; i < count; i++) {
    scanf("%d", &array[i]);
  }

  // 포인터 이동하면서 출력
  int *p = array;
  for (int i = 0; i < count; i++) {
    print1DArray(p, count - i);  // (포인터, 출력 갯수)
    p++;                         // 포인터 이동
  }

  return 0;
}