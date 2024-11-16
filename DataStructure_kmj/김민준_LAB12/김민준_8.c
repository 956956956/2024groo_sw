#include <stdio.h>

typedef struct Person {
    char name[10];
    char phone_num[20];
    char address[30];
} person;

typedef struct Professor {
    person info;
    char major[10];
    char subject1[20];
    char subject2[20];
} professor;

int main() {
    professor a[5] = {
        {{"ȫ�浿", "011-1111-1111", "����� ���α� ��ô��"}, "�����", "��ü����", "�м�����"},
        {{"����ȣ", "011-2222-2456", "��⵵ �Ⱦ�� ��굿"}, "�����", "C ���", "�ڹ��Թ�"},
        {{"������", "012-3333-2456", "��õ������ ������"}, "�����", "��ǻ�Ͱ���", "���α׷���"},
        {{"������", "016-3467-2489", "����� ������ ���"}, "�����", "����ȸȭ", "����"},
        {{"�ſ���", "017-2222-2456", "��⵵ �ϻ�� ȭ�"}, "�����", "���ʼ���", "�̻����"}
    };

    printf("  �̸�       ��ȭ��ȣ               �ּ�               �а�       ������1      ������2\n");
    for (int i = 0; i < 5; i++) {
        printf(" %8s    %-15s %-20s     %-8s     %-10s     %-10s\n",
            a[i].info.name, a[i].info.phone_num, a[i].info.address, a[i].major, a[i].subject1, a[i].subject2);
    }

    return 0;
}
