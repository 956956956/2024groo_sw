#include <stdio.h>

int sumAry1D(int ary[], int size) {
  int i, sum = 0;
  for (i = 0; i < size; i++) {
    sum += ary[i];
  }

  return sum;
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

  int result = 0;
  for (int i = 0; i < m; i++) {
    int sum = sumAry1D(array[i], n);
    result += sum;
    printf("%d\n", sum, n);
  }

  printf("%d\n", result);

  return 0;
}