#include <math.h>
#include <stdio.h>

int checkTwins(int n) {
  if (n < 10) return 1;  // �� �ڸ� ���� ��� ���� �̷�

  int first = n % 10;          // xxxx1
  int second = (n / 10) % 10;  // xxx1x

  if (first != second) return 0;

  return checkTwins(n / 100);
}

int main() {
  int input;
  while (1) {
    scanf("%d", &input);

    if (input == 0) break;

    int num = input;
    int digit_count = 0;

    // �ڸ��� ���
    while (num > 0) {
      num /= 10;
      digit_count++;
    }

    if (digit_count % 2 == 0) {
      if (checkTwins(input))
        printf("yes\n");
      else
        printf("no\n");
    } else {
      int digits = log10(input);
      int divisor = pow(10, digits);
      int refined_input = input % divisor;  // ù ��° �ڸ� ����

      if (checkTwins(refined_input))
        printf("yes\n");
      else
        printf("no\n");
    }
  }
  return 0;
}
