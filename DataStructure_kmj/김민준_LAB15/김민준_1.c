#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	// 100보다 작은 수의 범위

	srand(time(NULL));
	int* num_list = (int*)malloc(sizeof(int) * 10);
	char ch;

	printf("정렬 전 배열 값 : -->\n");
	for (int i = 0; i < 10; i++) {
		*(num_list + i) = rand() % 100 + 1;
	}

	for (int i = 0; i < 10; i++) {
		if (i == 9) {
			printf("%d\n", num_list[i]);
			break;
		}
		printf("%d, ", num_list[i]);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (num_list[i] > num_list[j]) {
				int temp;
				temp = num_list[i];
				num_list[i] = num_list[j];
				num_list[j] = temp;
			}
		}
	}

	printf("정렬 후 배열 값 : -->\n");
	for (int i = 0; i < 10; i++) {
		if (i == 9) {
			printf("%d", num_list[i]);
			break;
		}
		printf("%d, ", num_list[i]);
	}
}