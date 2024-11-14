#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 101
typedef struct {
    int col;
    int row;
    int value;
} term;

term a[MAX_TERMS];
int ary[20][20] = { 0, };

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))  // SWAP ��ũ��

// �Լ� ����
void makematrix(int n);
void sortmatrix(int n);
void printarray(int ary[][20]);

int main()
{
    int num;

    printf("��� ��Ŀ� ���Ե� ������ ������ �Է��ϼ���: ");
    scanf_s("%d", &num);

    // ���� ����� ����� ��� ��ķ� ��ȯ
    makematrix(num);
    // ��� ����� ��, �� �������� ����
    sortmatrix(num);

    // ������ ���� ��� ���
    printf("������ 20x20 ���\n");
    printarray(ary);

    // ��� ��� ���
    printf("��� ��� ���\n");
    for (int i = 0; i <= num; i++)
        printf("��: %5d, ��: %5d, ��: %5d\n", a[i].row, a[i].col, a[i].value);

    return 0;
}

// �������� 20x20 ����� �����, �̸� ��� ��ķ� ��ȯ�ϴ� �Լ�
void makematrix(int n)
{
    int row, col, val;

    // ��� ����� ù ��° ���Ҵ� ����� ũ�� ����
    a[0].col = 20;
    a[0].row = 20;
    a[0].value = n;

    // ���� �õ� ����
    long seconds = (long)time(NULL);
    srand(seconds);

    // n���� ���� ���Ҹ� ��Ŀ� �߰�
    for (int i = 1; i <= n; i++) {
        row = rand() % 20;  // 0~19 ������ ���� ��
        col = rand() % 20;  // 0~19 ������ ���� ��
        val = rand() % 99 + 1;  // 1~99 ������ ���� ��

        // ary �迭�� �� ����
        ary[row][col] = val;

        // ��� ��Ŀ� �� ����
        a[i].row = row;
        a[i].col = col;
        a[i].value = val;
    }
}

// ��� ����� ��� �� ������ �����ϴ� �Լ�
void sortmatrix(int n)
{
    int i, j, min, temp;

    // ���� ������ ����Ͽ� ����
    for (i = 1; i <= n; i++) {
        min = i;
        for (j = i + 1; j <= n; j++) {
            // �� �������� ����, ���� ������ �� �������� ����
            if (a[j].row < a[min].row)
                min = j;
            else if (a[j].row == a[min].row)
                if (a[j].col < a[min].col)
                    min = j;
        }
        // SWAP ��ũ�θ� ����Ͽ� �� ���� ���� �ٲ�
        SWAP(a[i].col, a[min].col, temp);
        SWAP(a[i].row, a[min].row, temp);
        SWAP(a[i].value, a[min].value, temp);
    }
}

// 20x20 ����� ����ϴ� �Լ�
void printarray(int ary[][20])
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%5d", ary[i][j]);  // �� ���Ҹ� 5ĭ���� ���
        }
        printf("\n");  // �� �� ��� �� ����
    }
}
