#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int solution(int num)
{
	char clock_number[4][5];
	char num_list[5];
	sprintf(num_list, "%d", num);
	for (int i = 0; i < 4; i++) {
		int count = 0;
		int j = i;
		while (count != 4) {
			if (j == 4) j = 0;
			clock_number[i][count] = num_list[j++];
			count++;
		}
		clock_number[i][4] = '\0';
	}
	int res = atoi(clock_number[0]);
	for (int i = 1; i < 4; i++) {
		if (res > atoi(clock_number[i])) {
			res = atoi(clock_number[i]);
		}
	}

	return res;
}

int main()
{
	int num;
	int num_list[4];
	char ch;
	for (int i = 0; i < 4; i++) {
		scanf("%d%c", &num, &ch);
		num_list[i] = num;
	}

	num = 1000 * num_list[0] + 100 * num_list[1] + 10 * num_list[2] + num_list[3];
	num = solution(num);

	int check = 1110, res = 0;

	while (check != num) {
		check++;
		if (check % 10 == 0) continue;

		if (check == solution(check)) res++;
	}

	printf("%d", res);
}