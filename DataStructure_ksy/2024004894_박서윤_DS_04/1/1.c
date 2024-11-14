#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 101  // ����� �ִ� ���� ���� ���� (�ִ� 100�� ���Ҹ� ����)
typedef struct term {
    int col;    // �� ����
    int row;    // �� ����
    int value;  // ���� ��
} term;

term a[MAX_TERMS];  // ��� ����� ���� ������ �����ϴ� �迭
int ary[20][20] = { 0, };  // 20x20 ����� 0���� �ʱ�ȭ

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))  // �� ������ ��ȯ�ϴ� ��ũ��

// �Լ� ����
void makematrix(int n);  // ������ ��� ���� �Լ�
void sortmatrix(int n);  // ��� ����� �����ϴ� �Լ�
void printarray(int ary[][20]);  // ��� ��� �Լ�

int main()
{
    int num;

    // ����ڷκ��� ����� ���� ������ �Է¹���
    printf("������ ������ ���ÿ�: ");
    scanf("%d", &num);

    makematrix(num);  // ������ ��� ����
    sortmatrix(num);  // ��� ����� ��, �� ������ ����

    printf("Random generated Matrix\n");
    printarray(ary);  // ������ ��� ���

    printf("Sparse Matrix\n");
    // ��� ����� ��� (��, ��, �� ������ ���)
    for (int i = 0; i <= num; i++)
        printf("%5d %5d %5d\n", a[i].row, a[i].col, a[i].value);

    return 0;
}

// ������ ��� ���� �Լ�
void makematrix(int n)
{
    int row, col, val;
    int used[20][20] = { 0 };  // �ߺ��� ��ǥ ������ �����ϱ� ���� �迭

    // a[0]�� ����� ũ��(20x20)�� ���� ������ ����
    a[0].col = 20;
    a[0].row = 20;
    a[0].value = n;

    srand((unsigned int)time(NULL));  // ���� �õ� ����

    // n���� ���Ҹ� �������� ����
    for (int i = 1; i <= n; i++) {
        do {
            row = rand() % 20;  // 0~19 ������ �� ��ǥ ������ ����
            col = rand() % 20;  // 0~19 ������ �� ��ǥ ������ ����
        } while (used[row][col]);  // �̹� ���� ��ǥ��� �ٽ� ����

        val = rand() % 99 + 1;  // 1~99 ������ �� ������ ����

        ary[row][col] = val;  // ��Ŀ� ���� ����

        a[i].row = row;  // ��� ����� �� ���� ����
        a[i].col = col;  // ��� ����� �� ���� ����
        a[i].value = val;  // ��� ����� �� ����

        used[row][col] = 1;  // �ش� ��ǥ�� ���Ǿ����� ǥ��
    }
}

// ��� ����� ��, �� ������ �����ϴ� �Լ�
void sortmatrix(int n)
{
    term temp;  // �� ���Ҹ� ��ȯ�ϱ� ���� �ӽ� ����
    int i, j, min;

    // ���� ���� �˰����� �̿��� ����
    for (i = 1; i <= n; i++) {
        min = i;
        for (j = i + 1; j <= n; j++) {
            // ���� �������� ����, ���� ������ ���� �������� ����
            if (a[j].row < a[min].row)
                min = j;
            else if (a[j].row == a[min].row)
                if (a[j].col < a[min].col)
                    min = j;
        }

        // �ּҰ��� ���� ��ġ�� ��ȯ
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

// ����� ����ϴ� �Լ�
void printarray(int ary[][20])
{
    // 20x20 ����� ���
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%5d", ary[i][j]);  // 5ĭ ������ �ΰ� ���
        }
        printf("\n");
    }
}

/*
makematrix �Լ�: �������� ��� ����� ���Ҹ� �����Ͽ� 20x20 ��Ŀ� ä���ְ�, �ߺ� ��ǥ�� �����մϴ�.
sortmatrix �Լ�: ������ ��� ����� ��(row)�� ��(col) ������ ���� ������ ���� �����մϴ�.
printarray �Լ�: 20x20 ����� ����մϴ�.
���� �Լ�: ��ü���� ���α׷� ���� �帧�� ����ϸ�, ����ڷκ��� �Է��� �޾� ����� �����ϰ� ������ �� ����մϴ�.*/