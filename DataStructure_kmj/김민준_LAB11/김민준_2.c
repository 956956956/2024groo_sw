#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main() {
	char ch;
	int count = 0;
	printf("문자열을 입력하세요 : ");
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