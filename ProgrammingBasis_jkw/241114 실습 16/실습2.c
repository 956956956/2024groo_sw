#include <limits.h>
#include <stdio.h>

int findMin1D(int ary[], int size, int initMin) {
  int i, min;
  min = initMin;
  for (i = 0; i < size; i++) {
    if (ary[i] < min) min = ary[i];
  }
  return min;
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);

  int array[m][n];
  int min = INT_MAX;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &array[i][j]);
    }
    int new_min = findMin1D(array[i], n, min);
    min = findMin1D(array[i], n, min) < min ? new_min : min;
  }

  printf("%d\n", min);

  return 0;
}