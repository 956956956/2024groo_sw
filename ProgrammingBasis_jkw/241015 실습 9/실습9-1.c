#include <stdio.h>

int _max(int a, int b) { return a > b ? a : b; }
int max(int a, int b, int c) { return _max(_max(a, b), _max(b, c)); }

int _min(int a, int b) { return a < b ? a : b; }
int min(int a, int b, int c) { return _min(_min(a, b), _min(b, c)); }

// a, b, c 중 2번쨰로 큰 값 반환
int middle(int a, int b, int c) {
  if (a == max(a, b, c)) {
    if (b == min(a, b, c)) {
      return c;
    } else {
      return b;
    }
  } else if (b == max(a, b, c)) {
    if (a == min(a, b, c)) {
      return c;
    } else {
      return a;
    }
  } else {
    if (a == min(a, b, c)) {
      return b;
    } else {
      return a;
    }
  }
}

int main() {
  while (1) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if ((a == 0) && (b == 0) && (c == 0)) {
      return 0;
    }

    printf("%d %d %d\n", max(a, b, c), min(a, b, c), middle(a, b, c));
  }

  return 0;
}