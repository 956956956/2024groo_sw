#include <stdio.h>

// �����θ� 2������ ��ȯ�Ͽ� ����ϴ� �Լ� (���)
void printBin(int a) {
  if (a > 1) printBin(a / 2);
  printf("%d", a % 2);
}

// �Ҽ��θ� 2������ ��ȯ�Ͽ� ����ϴ� �Լ� (�ݺ�)
void printFloatBin(double a) {
  int count = 0;
  int hasPrinted = 0;

  while (a > 0 && count < 10) {
    a *= 2;
    int bit = (int)a;
    printf("%d", bit);
    a -= bit;
    count++;
    hasPrinted = 1;  // �ּ� �� �ڸ��� ���
  }

  // �Ҽ��ΰ� 0�̾ ����� ���� ���, "0" ���
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

    // ������ ���
    printBin(intPart);
    printf(".");

    // �Ҽ��� ���
    printFloatBin(fracPart);
    printf("\n");
  }
  return 0;
}
