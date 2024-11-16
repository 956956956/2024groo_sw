#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word[100];
	int size;

	printf("한 단어를 입력하세요. ->\n");
	scanf("%s", word);

	size = strlen(word);


	printf("\n입력한 단어를 반대로 출력합니다. ->\n");
	for (int i = size - 1; i >= 0; i--) {
		printf("%c", word[i]);
	}
}