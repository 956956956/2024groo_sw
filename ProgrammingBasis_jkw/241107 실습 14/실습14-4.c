#include <stdio.h>

// 정수부를 2진수로 변환하여 출력하는 함수 (재귀)
void printBin(int a) {
  if (a > 1) printBin(a / 2);
  printf("%d", a % 2);
}

// 소수부를 2진수로 변환하여 출력하는 함수 (반복)
void printFloatBin(double a) {
  int count = 0;
  int hasPrinted = 0;

  while (a > 0 && count < 10) {
    a *= 2;
    int bit = (int)a;
    printf("%d", bit);
    a -= bit;
    count++;
    hasPrinted = 1;  // 최소 한 자리는 출력
  }

  // 소수부가 0이어서 출력이 없는 경우, "0" 출력
  if (!hasPrinted) {
    printf("0");
  }
}

int main() {
  double input;
  while (1) {
    scanf("%lf", &input);

    if (input == 0) break;

    int intPart = (int)input;
    double fracPart = input - intPart;

    // 정수부 출력
    printBin(intPart);
    printf(".");

    // 소수부 출력
    printFloatBin(fracPart);
    printf("\n");
  }
  return 0;
}
