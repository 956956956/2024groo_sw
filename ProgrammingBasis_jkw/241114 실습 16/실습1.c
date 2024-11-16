#include <stdio.h>

void print1DArray(int d[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", d[i]);
  }
  printf("\n");
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);

  int array[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &array[i][j]);
    }
  }

  for (int i = 0; i < m; i++) {
    int *p = array[i];
    for (int j = 0; j < n; j++) {
      print1DArray(p + j, n - j);  // (포인터, 출력 갯수)
    }
  }

  return 0;
}