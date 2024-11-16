#include <stdio.h>

int isPrime(int x) {
  if (x < 2) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  scanf("%d", &n);

  if (isPrime(n)) {
    printf("prime\n");
  } else {
    printf("not prime\n");
  }

  return 0;
}