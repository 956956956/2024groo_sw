#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int count, start = 1, i;
	scanf("%d", &count);
	char* res = (char*)malloc(sizeof(char) * (count * 2));
	int* target = (int*)malloc(sizeof(int) * count);
	for (i = 0; i < count; i++) {
		scanf("%d", (target + i));
	}

	int num = 1, stack_point = 0, target_point = 0, check = 0;
	int* stack = (int*)malloc(sizeof(int) * count);

	while (target_point != count) {
		if (stack_point > 0 && stack[stack_point - 1] == target[target_point]) {
			stack_point--;
			target_point++;
			res[check++] = '-';
		}
		else if (num <= count) {
			stack[stack_point++] = num++;
			res[check++] = '+';
		}
		else {
			break;
		}
	}

	if (target_point == count) {
		for (int i = 0; i < check; i++) {
			printf("%c\n", res[i]);
		}
	}
	else {
		printf("NO");
	}

}