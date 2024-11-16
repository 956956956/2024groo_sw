#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char ch;
	printf("문자를 하나 입력하세요 -> ");
	scanf("%c", &ch);
	printf("\n%c의 아스키 코드 값은 십진수로 %d입니다.", ch, ch);
}