#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {

	FILE* s,*d;
	char word[1000];

	s = fopen(argv[1], "r");
	d = fopen(argv[2], "a");

	fputs("\n", d);

	while (!feof(s)) {
		fgets(word, 1000, s);
		fputs(word, d);
	}

	fclose(s);
	fclose(d);

}