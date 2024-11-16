#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word[102];
	char* ptoken;
	int size;
	printf("한 줄의 문장을 입력하세요. ->\n");
	fgets(word, 102, stdin);

	size = strlen(word);

	printf("\n입력한 각각의 단어를 반대로 출력합니다. ->\n");

	ptoken = strtok(word, " ");

	while (ptoken != NULL) {
		size = strlen(ptoken);
		for (int i = size - 1; i >= 0; i--) {
			if (ptoken[i] == '\n') {
				continue;
			}
			printf("%c", ptoken[i]);
		}
		printf(" ");
		ptoken = strtok(NULL, " ");
	}
}