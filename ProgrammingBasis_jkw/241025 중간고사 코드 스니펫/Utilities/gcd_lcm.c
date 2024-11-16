#include <stdio.h>

// 최대 공약수 반환
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

// 최소 공배수 반환
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  int a = 12, b = 18;
  printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
  printf("lcm(%d, %d) = %d\n", a, b, lcm(a, b));
  return 0;
}