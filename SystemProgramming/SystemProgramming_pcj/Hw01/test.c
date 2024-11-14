#include <stdio.h>

int main() {
	if (1 && printf("abc")) {
		printf("d");
	}
	printf("i\n");

	return 0;
}