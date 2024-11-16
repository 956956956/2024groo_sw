#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

    float res = 0.0;
    char ch[2], name[100], score1[6], score2[6];
    FILE* f;
    FILE* n;

    f = fopen("tst.txt", "r");

    n = fopen("output.txt", "w");


    while (!feof(f)) {
        res = 0.0;

        fscanf(f, "%s %s %s %s", ch, name, score1, score2);
        res = atof(score1) + atof(score2);
        fprintf(n, "%s    %s    %s     %s     %.1f\n", ch, name, score1, score2, res);
    }

    fclose(f);
    fclose(n);
}
