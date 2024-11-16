#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word_list[5][102];
	int check[5] = {0,1,2,3,4};
	printf("입력 : ");
	for (int i = 0; i < 5; i++) {
		fgets(word_list[i], 102, stdin);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (strcmp(word_list[i],word_list[j]) > 0) {
				int temp = check[i];
				check[i] = check[j];
				check[j] = temp;
			}
		}
	}

	printf("\n");
	printf("정렬 결과\n");
	for (int i = 0; i < 5; i++) {
		printf("%s", word_list[check[i]]);
	}
}