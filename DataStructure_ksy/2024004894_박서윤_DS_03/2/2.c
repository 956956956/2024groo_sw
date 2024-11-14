/* 2.�Է� ���� ������ �迭�� ���� ���� ���� ���� �Լ� make2dArray()�� �����ϸ�, �Լ�
make2dArray()�� ���� ���� ���� ���� ��ŭ �������� �޸𸮸� �Ҵ� �޾� �������� 100����
���� ������ �޸𸮸� �ʱ�ȭ ��Ų ��, �ּҰ��� ��ȯ�Ѵ�. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** make2dArray(int rows, int cols) {
    int** arr = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(sizeof(int) * cols);
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }
    return arr;
}

int main() {
    int** ipp;
    int i, j, rows, cols;
    printf("������ �迭�� ��� ���� ���� �Է��ϼ���: ");
    scanf_s("%d %d", &rows, &cols);

    // 2���� �迭 ����
    ipp = make2dArray(rows, cols);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("ipp[%d][%d] = %d ", i, j, ipp[i][j]);
        }
        printf("\n");
    }
    return 0; // break point ����
}