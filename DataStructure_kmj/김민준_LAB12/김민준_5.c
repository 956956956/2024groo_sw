#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char a[100][102];
	int count = 1, full_stop_count = 1;
	printf("���� �ٿ� ���ϴ� ������ �Է��ϼ���.�Է��� �� �Ǿ�����\n���ο� �� ó���� ctrl+Z, �׸��� Enter�� �Է��ϼ���.\n\n");

	while (1) {
		if (fgets(a[count++], 102, stdin) == NULL) {
			break;
		}
	}

	printf("\n");

	for (int i = 1; i < count  -1; i++) {
		int size = strlen(a[i]);
		printf("<< %d�ٿ� �Է��� ���ڿ����� ������ ��� >>\n", i);
		for (int j = 0; j < size; j++) {
			if (a[i][j] == '.') {
				printf("������ %d : .\n", full_stop_count++);
			}
			if (a[i][j] == ',') {
				printf("������ %d : ,\n", full_stop_count++);
			}
			if (a[i][j] == '!') {
				printf("������ %d : !\n", full_stop_count++);
			}
			if (a[i][j] == '?') {
				printf("������ %d : ?\n", full_stop_count++);
			}
		}
	}

	printf("\n�������� ���� ��� %d�� �Դϴ�.", --full_stop_count);
}