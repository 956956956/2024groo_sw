#define _CRT_SECURE_NO_WARNINGS
#define SIZE 1002
#include <stdio.h>
#include <string.h>

int strist(char* src, char* ist, int index) {

	char res[SIZE];
	int src_count = strlen(src) - 2;
	int ist_count = strlen(ist) - 2;
	int i = 0, j = 0;

	if (src_count < index) {
		return 0;
	}

	for (i; i <= src_count + ist_count + 2; i++) {
		if (i == index) {
			for (j = 0; j <= ist_count; j++) {
				res[i++] = ist[j];
			}
			i--;
			j++;
		}
		else {
			res[i] = src[i - j];
		}
	}
	res[i] = '\0';

	strcpy(src, res);

	return 1;
}

int main() {
	printf("origin string : ");
	char ch;
	char word[SIZE];
	char insert[SIZE];
	fgets(word, SIZE, stdin);
	printf("string to insert : ");
	fgets(insert, SIZE, stdin);

	if (strist(word, insert, 8)) {
		printf("result : %s", word);
	}
	else {
		printf("index°¡ ¹üÀ§¸¦ ¹þ¾î³µ½À´Ï´Ù.");
	}

}