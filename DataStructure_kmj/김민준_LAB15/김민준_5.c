#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int count,check = 1;
	scanf("%d", &count);

	int** num_list = (int**)malloc(sizeof(int*) * count);

	for (int i = 1; i <= count; i++) {
		num_list[i - 1] = (int*)malloc(sizeof(int) * count);
		if (i % 2 == 1) {
			for (int j = 1; j <= count; j++) {
				num_list[i - 1][j - 1] = check++;;
			}
		}
		else {
			for (int j = count; j >= 1; j--) {
				num_list[i - 1][j - 1] = check++;
			}
		}
	}

	for (int i = 1; i <= count; i++) {
		for (int j = 1; j <= count; j++) {
			printf(" %3d", num_list[i - 1][j - 1]);
		}
		printf("\n");
	}

}