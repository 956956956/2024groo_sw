#include <stdio.h>

// 특정 수 배수의 합을 구하는 함수
int sumMultiple(int start, int end, int x) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    if (i % x == 0) {
      sum += i;
    }
  }
  return sum;
}

// n의 배수면서 m의 배수인 수 합을 구하는 함수
int sumMultipleNM(int start, int end, int n, int m) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    if (i % n == 0 && i % m == 0) {
      sum += i;
    }
  }
  return sum;
}

// n의 배수거나 m의 배수인 수 합
int sumMultipleNOrM(int start, int end, int n, int m) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    if (i % n == 0 || i % m == 0) {
      sum += i;
    }
  }
  return sum;
}

// m의 배수면서 n의 배수가 아닌 수 합
int sumMultipleMNotN(int start, int end, int n, int m) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    if (i % m == 0 && i % n != 0) {
      sum += i;
    }
  }
  return sum;
}

// n의 배수도 아니고 m의 배수도 아닌 수의 합
int sumMultipleNotNM(int start, int end, int n, int m) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    if (i % n != 0 && i % m != 0) {
      sum += i;
    }
  }
  return sum;
}

int main() {
  int start, end, n, m;
  scanf("%d %d %d %d", &start, &end, &n, &m);

  // 1. n 배수 합
  printf("%d\n", sumMultiple(start, end, n));

  // 2. m 배수 합
  printf("%d\n", sumMultiple(start, end, m));

  // 3. n의 배수면서 m의 배수인 수 합
  printf("%d\n", sumMultipleNM(start, end, n, m));

  // 4. n의 배수거나 m의 배수인 수 합
  printf("%d\n", sumMultipleNOrM(start, end, n, m));

  // 5. m의 배수면서 n의 배수가 아닌 수 합
  printf("%d\n", sumMultipleMNotN(start, end, n, m));

  // 6. n의 배수도 아니고 m의 배수도 아닌 수의 합
  printf("%d\n", sumMultipleNotNM(start, end, n, m));

  return 0;
}