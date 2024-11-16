#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
	char name[20];
	int score;
	char grade[3];
	int scholarship;
}student;

int solution(student* a) {

	if (a->score >= 80) {
		strcpy(a->grade, "A");
		a->scholarship = 10000000;
	}
	else if (60 <= a->score && a->score < 80) {
		strcpy(a->grade, "B");
		a->scholarship = 5000000;
	}
	else{
		strcpy(a->grade, "C");
		a->scholarship = 0;
	}

}

int main(int argc, char* argv[]) {

	student a;

	strcpy(a.name, argv[1]);
	a.score = atoi(argv[2]);

	solution(&a);

	printf("�л��� �̸��� �Է��ϼ��� : %s\n", a.name);
	printf("�л��� ���� ������ �Է��ϼ��� : %d\n", a.score);

	printf("\n\n");

	printf("%s �л��� ����� %s�̸� %d���� ���б��� �޽��ϴ�.", a.name, a.grade, a.scholarship);
}