#include <stdio.h>

int main() {
  int arr[2][5] = {};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < 5; i++) {
    if (arr[0][i] != arr[1][i]) {
      printf("not same");
      return 0;
    }
  }
  printf("same");

  return 0;
}