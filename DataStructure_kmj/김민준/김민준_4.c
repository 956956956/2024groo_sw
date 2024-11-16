#define _CRT_SECURE_NO_WARNINGS
#define SWAP(x,y,t)((t) = (x), (x) = (y), (y) = (t))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char guitar_name[]) {
	int res = 0, i = 0, check = 0;

	while (guitar_name[i] != '\0') {
		if (48 <= guitar_name[i] && guitar_name[i] <= 57) {
			res += guitar_name[i] - 48;
			check = 1;
		}
		i++;
	}

	return res;
}

int main()
{
	// 시리얼 번호 받기
	int temp;
	int guitar_count;
	scanf("%d", &guitar_count);
	char** guitar_list = (char**)calloc(guitar_count, sizeof(char*));
	char guitar_name[51];
	for (int i = 0; i < guitar_count; i++) {
		scanf("%s", guitar_name);
		int size = strlen(guitar_name);
		guitar_list[i] = (char*)calloc(size + 1, sizeof(char));
		strcpy(guitar_list[i], guitar_name);
	}
	int* change_list = (int*)calloc(guitar_count, sizeof(int));
	for (int i = 0; i < guitar_count; i++) {
		*(change_list + i) = i;
	}

	// 첫 번째 규칙 - 길이가 짧은 순서대로 배치

	for (int i = 0; i < guitar_count - 1; i++) {
		for (int j = i + 1; j < guitar_count; j++) {
			if (strlen(guitar_list[change_list[i]]) > strlen(guitar_list[change_list[j]])) {
				SWAP(change_list[i], change_list[j], temp);
			}
		}
	}


	// 두 번째 규칙 - 길이가 같다면 각 시리얼 번호의 숫자부분만 더해서 작은 것부터 정렬하기 and 세 번째 규칙 - 사전 순 배치
	int start = 0;
	for (int i = 0; i < guitar_count; i++) {
		if (i != guitar_count - 1 && strlen(guitar_list[change_list[i]]) == strlen(guitar_list[change_list[i + 1]])) continue;
		for (int j = start; j < i; j++) {
			for (int k = j + 1; k <= i; k++) {
				if (check(guitar_list[change_list[j]]) > check(guitar_list[change_list[k]])) {
					SWAP(change_list[j], change_list[k], temp);
				}
				else if (check(guitar_list[change_list[j]]) == check(guitar_list[change_list[k]]))
				{
					if (strcmp(guitar_list[change_list[j]], guitar_list[change_list[k]]) > 0) {
						SWAP(change_list[j], change_list[k], temp);
					}
				}
			}
		}
		start = i + 1;
	}

	for (int i = 0; i < guitar_count; i++) {
		printf("%s\n", guitar_list[change_list[i]]);
	}
}