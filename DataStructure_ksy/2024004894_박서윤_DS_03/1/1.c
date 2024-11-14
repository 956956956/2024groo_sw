/*1. �Է� ���� ������ �迭�� ���� ������ �Լ� make1dArray()�� �����ϸ�, �Լ�
make1dArray()�� ���� ���� ���� ���� ��ŭ �������� �޸𸮸� �Ҵ� �޾� �������� 100
���� ���� ������ �޸𸮸� �ʱ�ȭ ��Ų ��, �ּҰ��� ��ȯ�Ѵ�. (�� �Լ� ȣ��� 1���� �迭 �����)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* make1dArray(int size) {
	int* arr = (int*)malloc(sizeof(int) * size);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}
	return arr;
}

int main() {
	int* ipp;
	int i, num;

	printf("������ �迭�� ���� �Է��ϼ���: ");
	scanf_s("%d", &num);

	ipp = make1dArray(num);
	for (i = 0; i < num; i++) {
		printf("ipp[%2d] =%2d ", i, ipp[i]);
		if ((i % 5) == 4)
			printf("\n");
	}
	return 0;

}