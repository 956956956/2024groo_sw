#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char a[100][102];
	int count = 1, full_stop_count = 1;
	printf("여러 줄에 원하는 문장을 입력하세요.입력이 다 되었으면\n새로운 줄 처음에 ctrl+Z, 그리고 Enter를 입력하세요.\n\n");

	while (1) {
		if (fgets(a[count++], 102, stdin) == NULL) {
			break;
		}
	}

	printf("\n");

	for (int i = 1; i < count  -1; i++) {
		int size = strlen(a[i]);
		printf("<< %d줄에 입력한 문자열에서 구두점 출력 >>\n", i);
		for (int j = 0; j < size; j++) {
			if (a[i][j] == '.') {
				printf("구두점 %d : .\n", full_stop_count++);
			}
			if (a[i][j] == ',') {
				printf("구두점 %d : ,\n", full_stop_count++);
			}
			if (a[i][j] == '!') {
				printf("구두점 %d : !\n", full_stop_count++);
			}
			if (a[i][j] == '?') {
				printf("구두점 %d : ?\n", full_stop_count++);
			}
		}
	}

	printf("\n구두점의 수는 모두 %d개 입니다.", --full_stop_count);
}