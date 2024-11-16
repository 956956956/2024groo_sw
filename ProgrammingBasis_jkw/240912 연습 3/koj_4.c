#include <stdio.h>

int main() {
  int money = 28777;

  scanf("%d", &money);

  int m_10000 = money / 10000;
  money -= 10000 * m_10000;

  int m_5000 = money / 5000;
  money -= 5000 * m_5000;

  int m_1000 = money / 1000;
  money -= 1000 * m_1000;

  int m_500 = money / 500;
  money -= 500 * m_500;

  int m_100 = money / 100;
  money -= 100 * m_100;

  int m_50 = money / 50;
  money -= 50 * m_50;

  int m_10 = money / 10;
  money -= 10 * m_10;

  int m_5 = money / 5;
  money -= 5 * m_5;

  int m_1 = money;

  printf("10000:%d\n", m_10000);
  printf("5000:%d\n", m_5000);
  printf("1000:%d\n", m_1000);
  printf("500:%d\n", m_500);
  printf("100:%d\n", m_100);
  printf("50:%d\n", m_50);
  printf("10:%d\n", m_10);
  printf("5:%d\n", m_5);
  printf("1:%d", m_1);

  return 0;
}