#include <stdio.h>

int main() {
  int x = 75;
  int mask;

  // 1번 답
  printf("%d\n", x >> 5 & 1);

  // 2번 답
  mask = 0b11100;
  printf("%d\n", x | mask);

  // 3번 답
  mask = ~((1 << 2) | (1));
  printf("%d\n", x & mask);

  // 4번 답
  mask = (1 << 3) | (1 << 2);
  printf("%d\n", x ^ mask);

  return 0;
}