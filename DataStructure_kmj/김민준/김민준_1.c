#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solution(int num, int digit) {
	if (digit == 1) return 0;
	char* num_list = (char*)calloc(digit + 1, sizeof(char));
	sprintf(num_list, "%d", num);
	for (int i = 0; i < digit - 1; i++) {
		if (*(num_list + i) <= *(num_list + (i + 1))) return digit - (i + 1);
	}
	return 0;
}

int main() // 이번에는 그냥 digit가 바로 자릿수
{
	int count, num = 1, digit = 1;
	scanf("%d", &count);
	int finish = count == 0 ? 1 : 0;

	if (count < 1022) {
		while (count > 0) {
			if (num >= (int)pow(10, digit)) {
				digit++;
			}
			int check = solution(num, digit);

			if (check == 0) {
				count--;
				if (count > 0)num++;
			}
			else {
				if (num == (int)pow(10, digit - 1)) {
					num += (int)pow(10, digit - 2);
				}
				else {
					int factor = (int)pow(10, check);
					num = ((num / factor) + 1) * factor;
				}
			}

		}
	}

	if (count < 1022) {
		printf("%d", finish ? 0 : num);
	}
	else if (count == 1022) {
		double a = 9876543210;
		printf("%.0lf", a);
	}
	else if (count > 1022) {
		printf("%d", -1);
	}
}