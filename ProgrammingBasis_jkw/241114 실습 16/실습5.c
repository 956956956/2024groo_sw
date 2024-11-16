#include <stdio.h>
#define MAXBUFSIZE 100
void print1DArray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
}
int main() {
  int* p[4] = {
      NULL,
  };

  int a[4][5];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  /* 정답 제출 여기부터 */
  p[0] = a[1];
  p[1] = a[3];
  p[2] = a[0];
  p[3] = a[2];
  /* 정답 제출 여기까지 */

  for (int i = 0; i < 4; i++) {
    print1DArray(p[i], 5);
  }

  return 0;
}