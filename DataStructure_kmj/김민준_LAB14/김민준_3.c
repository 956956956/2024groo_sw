#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

	FILE* f;
	char word[100];

	f = fopen(argv[1], "r");

	printf("원래의 파일 내용 출력 : -->\n\n");
	while (!feof(f)) {
		fgets(word, 100, f);
		fputs(word, stdout);
	}

	fclose(f);
	f = fopen(argv[1], "r");

	printf("\n\n\n변환된 파일 내용 출력 : -->\n\n");
	while (!feof(f)) {
		fgets(word, 100, f);
		int size = strlen(word);
		for (int i = 0; i < size; i++) {
			if (islower(word[i])) {
				printf("%c", toupper(word[i]));
			}
			else if(isupper(word[i])) {
				printf("%c", towlower(word[i]));
			}
			else {
				printf("%c", word[i]);
			}
		}
	}

	fclose(f);

}