#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int start, finish, res = 0;
	scanf("%d %d", &start, &finish);

	for (int i = start; i <= finish; i++) {
		if (i % 10 == 4 || i % 10 == 7) {
			int num = i;
			while (num > 0) {
				if (num % 10 != 4 && num % 10 != 7) {
					break;
				}
				num /= 10;
			}
			if (!num) {
				res++;
			}
		}
		else {
			continue;
		}
	}

	printf("%d", res);
}