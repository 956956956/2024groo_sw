#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct People {

	int num;
	char name[10];
	float score_1;
	float score_2;
	float score_sum;
	struct People* next;

}person;


int main() {

	FILE* f,*o;
	f = fopen("input.txt", "r");
	char word[256];
	int count = 0;

	while (fgets(word, 256, f) != NULL) {
		count++;
	}

	fclose(f);
	f = fopen("input.txt", "r");

	person* list = (person*)malloc(sizeof(person) * count);

	for (int i = 0; i < count; i++) {
		fscanf(f, "%d%s%f%f", &(list + i)->num, (list + i)->name, &(list + i)->score_1, &(list + i)->score_2);
		(list + i)->score_sum = (list + i)->score_1 + (list + i)->score_2;
	}

	for (int i = 0; i < count - 1; i++) {
		(list + i)->next = (list + i + 1);
	}

	(list + (count - 1))->next = NULL;

	printf("%4d   %5s %5.1f %5.1f %6.1f\n", (list + 0)->num, (list + 0)->name, (list + 0)->score_1, (list + 0)->score_2, (list + 0)->score_sum);

	for (int i = 0; i < count - 1; i++) {
		printf("%4d   %5s %5.1f %5.1f %6.1f\n",
			((list + i)->next)->num, ((list + i)->next)->name, ((list + i)->next)->score_1, ((list + i)->next)->score_2, ((list + i)->next)->score_sum);
	}

	o = fopen("output.txt", "w");

	fprintf(o,"%4d   %5s %5.1f %5.1f %6.1f\n", (list + 0)->num, (list + 0)->name, (list + 0)->score_1, (list + 0)->score_2, (list + 0)->score_sum);

	for (int i = 0; i < count - 1; i++) {
		fprintf(o,"%4d   %5s %5.1f %5.1f %6.1f\n",
			((list + i)->next)->num, ((list + i)->next)->name, ((list + i)->next)->score_1, ((list + i)->next)->score_2, ((list + i)->next)->score_sum);
	}
}