#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	char ch;
	int count = 0;
	printf("���ڿ��� �Է��ϼ��� : ");
	while ((ch = getchar()) != '\n') {
		count++;
	}
	printf("���ڿ��� ���̴� %d�Դϴ�.", count);
}