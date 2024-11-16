#include <stdio.h>

int main() {
  int money = 37970;

  printf("%d원은\n", money);

  int m_10000 = money / 10000;
  money -= 10000 * m_10000;
  int m_5000 = money / 5000;
  money -= 5000 * m_5000;
  int m_1000 = money / 1000;
  money -= 1000 * m_1000;
  int m_100 = money / 100;
  money -= 100 * m_100;
  int m_10 = money / 10;
  money -= 10 * m_10;

  printf("만원짜리 %d개\n", m_10000);
  printf("오천원짜리 %d개\n", m_5000);
  printf("천원짜리 %d개\n", m_1000);
  printf("백원짜리 %d개\n", m_100);
  printf("십원짜리 %d개로 구성됩니다.", m_10);

  return 0;
}
