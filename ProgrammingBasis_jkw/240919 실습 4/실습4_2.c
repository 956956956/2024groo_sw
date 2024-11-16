#include <stdio.h>

int main() {
  int x = 75;
  int mask;

  // 1�� ��
  printf("%d\n", x >> 5 & 1);

  // 2�� ��
  mask = 0b11100;
  printf("%d\n", x | mask);

  // 3�� ��
  mask = ~((1 << 2) | (1));
  printf("%d\n", x & mask);

  // 4�� ��
  mask = (1 << 3) | (1 << 2);
  printf("%d\n", x ^ mask);

  return 0;
}