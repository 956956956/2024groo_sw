#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum a {
	false, true
}boolean;

int main() {

	int num_list[10];
	int point = 0;
	char ch;

	boolean a;

	a = true;


	printf("ют╥б : ");
	while (1) {
		scanf("%c", &ch);
		if (ch == '\n') {
			break;
		}
		if (48 <= ch && ch <= 57) {
			num_list[point++] = ch;
		}
	}

	for (int i = 1; i < point; i++) {
		if (num_list[0] < num_list[i]) {
			a = false;
		}
	}

	if (a) {
		printf("TRUE");
	}
	else {
		printf("FALSE");
	}

	

}