#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

	FILE* f;
	int count_line = 0, count_char = 0, count_word = 0;
	char word[1000];


	f = fopen(argv[1], "r");

	while (!feof(f)) {
		count_line++;
		fgets(word, 1000, f);
		int size = strlen(word);
		for (int i = 0; i < size; i++) {
			if (isalpha(word[i])) {
				count_char++;
			}
			else if (isdigit(word[i])) {
				count_char++;
			}
			else if (word[i] == 32) {
				count_word++;
			}
			else if (word[i] == '.' || word[i] == ',' || word[i] == '?' || word[i] == '!') {
				count_char++;
			}
		}
	}

	count_word += count_line;

	printf("\n\n\n               Analysis Result\n");
	printf("-----------------------------------------------\n");
	printf("               Count of Character : %d\n",count_char);
	printf("               Count of Word : %d\n",count_word);
	printf("               Count of Line : %d\n",count_line);
	
	fclose(f);

}