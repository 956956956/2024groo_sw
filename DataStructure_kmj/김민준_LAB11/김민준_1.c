#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	char ch;
	int count = 0;
	printf("문자열을 입력하세요 : ");
	while ((ch = getchar()) != '\n') {
		count++;
	}
	printf("문자열의 길이는 %d입니다.", count);
}