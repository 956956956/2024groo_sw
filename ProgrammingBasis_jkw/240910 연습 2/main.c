#include <stdio.h>

int main() {
  int money = 37970;

  printf("%d����\n", money);

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

  printf("����¥�� %d��\n", m_10000);
  printf("��õ��¥�� %d��\n", m_5000);
  printf("õ��¥�� %d��\n", m_1000);
  printf("���¥�� %d��\n", m_100);
  printf("�ʿ�¥�� %d���� �����˴ϴ�.", m_10);

  return 0;
}
