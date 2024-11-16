#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
	if (num == 1) return 1;

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return 1;
	}

	return 0;
}

int main()
{
	int num_count, difference;
	scanf("%d %d", &num_count, &difference);

	int num = 1, i;
	int* res_list = (int*)calloc(num_count, sizeof(int));

	while (num < 2000001) {
		if (is_prime(num) == 0) {
			num++;
			continue;
		}
		for (i = 0; i < num_count; i++) {
			if (is_prime(num + difference * i) == 0) {
				break;
			}
			*(res_list + i) = num + difference * i;
		}

		if (num_count == i) {
			break;
		}
		else {
			num++;
		}
	}

	if (num > 2000000) {
		printf("%d", -1);
	}
	else {
		for (int j = 0; j < num_count; j++) {
			printf("%d ", *(res_list + j));
		}
	}

}