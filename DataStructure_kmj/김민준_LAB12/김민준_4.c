#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word[102];
	char* ptoken;
	int size;
	printf("�� ���� ������ �Է��ϼ���. ->\n");
	fgets(word, 102, stdin);

	size = strlen(word);

	printf("\n�Է��� ������ �ܾ �ݴ�� ����մϴ�. ->\n");

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