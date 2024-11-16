#include <stdio.h>

int main() {
  int n;
  int result = 0;
  int max_n = 0;

  scanf("%d", &n);

  int input;
  for (int i = 0; i < n; i++) {
    scanf("%d", &input);

    if (input > max_n) {
      max_n = input;
    }
    result += input;
  }

  printf("%d\n%d", result, max_n);

  return 0;
}