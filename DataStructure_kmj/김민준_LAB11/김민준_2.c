#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main() {
	char ch;
	int count = 0;
	printf("���ڿ��� �Է��ϼ��� : ");
	while ((ch = getchar()) != '\n') {
		if (isupper(ch)) {
			printf("%c", tolower(ch));
		}
		else if (islower(ch)) {
			printf("%c", toupper(ch));
		}
		else {
			printf("%c", ch);
		}
	}

}