#include <stdio.h>

// Ư�� �� ����� ���� ���ϴ� �Լ�
int sumMultiple(int start, int end, int x) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    if (i % x == 0) {
      sum += i;
    }
  }
  return sum;
}

// n�� ����鼭 m�� ����� �� ���� ���ϴ� �Լ�
int sumMultipleNM(int start, int end, int n, int m) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    if (i % n == 0 && i % m == 0) {
      sum += i;
    }
  }
  return sum;
}

// n�� ����ų� m�� ����� �� ��
int sumMultipleNOrM(int start, int end, int n, int m) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    if (i % n == 0 || i % m == 0) {
      sum += i;
    }
  }
  return sum;
}

// m�� ����鼭 n�� ����� �ƴ� �� ��
int sumMultipleMNotN(int start, int end, int n, int m) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    if (i % m == 0 && i % n != 0) {
      sum += i;
    }
  }
  return sum;
}

// n�� ����� �ƴϰ� m�� ����� �ƴ� ���� ��
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

  // 1. n ��� ��
  printf("%d\n", sumMultiple(start, end, n));

  // 2. m ��� ��
  printf("%d\n", sumMultiple(start, end, m));

  // 3. n�� ����鼭 m�� ����� �� ��
  printf("%d\n", sumMultipleNM(start, end, n, m));

  // 4. n�� ����ų� m�� ����� �� ��
  printf("%d\n", sumMultipleNOrM(start, end, n, m));

  // 5. m�� ����鼭 n�� ����� �ƴ� �� ��
  printf("%d\n", sumMultipleMNotN(start, end, n, m));

  // 6. n�� ����� �ƴϰ� m�� ����� �ƴ� ���� ��
  printf("%d\n", sumMultipleNotNM(start, end, n, m));

  return 0;
}