#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char word[100];
	int size;

	printf("�� �ܾ �Է��ϼ���. ->\n");
	scanf("%s", word);

	size = strlen(word);


	printf("\n�Է��� �ܾ �ݴ�� ����մϴ�. ->\n");
	for (int i = size - 1; i >= 0; i--) {
		printf("%c", word[i]);
	}
}