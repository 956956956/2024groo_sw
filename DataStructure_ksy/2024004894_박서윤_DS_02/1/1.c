#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* func1() {
    int* p = (int*)malloc(sizeof(int));  // int ũ�⸸ŭ �����Ҵ�
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    *p = 10;  // 10�� ����
    return p;
}

void func2(int* p) {
    if (p != NULL) {
        *p = 100;  // �����Ͱ� ����Ű�� �� ����
    }
}

void func3(int** p) {
    if (p != NULL && *p != NULL) {
        **p = 200;  // ���� �����͸� ���� �� ����
    }
}

char* func4(int size) {
    char* p = (char*)malloc(size * sizeof(char));  // size��ŭ �����Ҵ�
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return p;
}

int main(void) {
    int* pNum;
    char* pChar;

    pNum = func1();  // int ũ�⸸ŭ �����Ҵ� �޾� 10�� ���� �� ������ ������ ����
    printf("%d\n", *pNum);

    func2(pNum);  // pNum�� ����Ű�� ���� 100���� ����
    printf("%d\n", *pNum);

    func3(&pNum);  // pNum�� ����Ű�� ���� 200���� ����
    printf("%d\n", *pNum);

    pChar = func4(100);  // pChar�� 100 byte �Ҵ���� �޸𸮿� Ű����κ��� �Է� ���� ���ڿ� ����
    char string[100];
    printf("Enter a string: ");
    scanf_s("%99s", string, sizeof(string));  // �ִ� 99�ڱ��� �Է�

    strncpy_s(pChar, 100, string, strlen(string));  // �����ϰ� ���ڿ� ����
    pChar[99] = '\0';  // ������ ����Ʈ�� �� ���� �߰�

    printf("pChar contents = %s\n", pChar);

    free(pNum);
    pNum = NULL;  // free �� NULL�� �ʱ�ȭ

    free(pChar);
    pChar = NULL;  // free �� NULL�� �ʱ�ȭ
    return 0;
}
