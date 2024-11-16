#include <stdio.h>

int main() {
  int a;
  scanf("%d", &a);

  while (1) {
    if (a < 0) {
      printf("wrong\n");
      scanf("%d", &a);
      continue;
    } else {
      break;
    }
  }

  int money = 1;
  int result = 0;
  for (int i = 0; i < a; i++) {
    printf("%d\n", money);
    result += money;
    money *= 2;
  }
  printf("=%d\n", result);

  return 0;
}