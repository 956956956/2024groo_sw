#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	FILE* s, *d;
	char word[100];

	s = fopen(argv[1], "r");
	d = fopen(argv[2], "w");

	while (!feof(s)) {
		fgets(word, 100, s);
		fputs(word, d);
	}

	fclose(s);
	fclose(d);
}