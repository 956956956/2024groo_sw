#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int queue[1000000];
int start = 0, finish = 0;

int pop(int* a) {
	start++;
	return 0;
}

int move(int* a) {
	queue[finish++] = queue[start++];
	return 0;
}

int main() {
	int count;
	scanf("%d", &count);
	for (int i = 0; i < count; i++) {
		queue[i] = i + 1;
	}
	finish = count;

	if (count == 1) {
		printf("%d", 1);
	}
	else {
		while (start != finish - 1) {
			pop(queue);
			if (start == finish - 1) {
				printf("%d", queue[start]);
			}
			move(queue);
		}
	}
}