#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 24

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
}node;

int stack[MAX_SIZE];
int top = -1;

void push(int data);
int pop();
void initRelate(int i, int j, nodePointer seq[]);
void equivalence(int n, bool out[], nodePointer seq[]);
void printList(int n, nodePointer seq[]);

void push(int data) {
	if (top >= MAX_SIZE - 1)	// ���� ���� �� ����
		return;
	stack[++top] = data;
}
int pop() {
	if (top < 0)	// ���� �����
		return -1;
	return stack[top--];
}

void initRelate(int i, int j, nodePointer seq[]) {
	nodePointer x, y;
	x = (nodePointer)malloc(sizeof(*x));
	if (!x) return;
	x->data = j; x->link = seq[i]; seq[i] = x;

	y = (nodePointer)malloc(sizeof(*x));
	if (!y) return;
	y->data = i; y->link = seq[j]; seq[j] = y;
}

void equivalence(int n, bool out[], nodePointer seq[])
{
	nodePointer x;
	int j;
	for (int i = 0; i < n; i++) {
		if (out[i]) {
			printf("\nNew class: %5d", i);
			out[i] = false;
			x = seq[i]; top = -1;

			for (;;) {		// i�� ��ġ�� ������ ������ ��� ã��
				while (x) {	// x�� NULL�� �ƴ� ����
					j = x->data;
					if (out[j]) {
						printf("%5d", j); out[j] = false;
						push(j);
					}
					x = x->link;
				}
				if (top == -1) break;
				x = seq[pop()];
			}
		}
	}
}

void printList(int n, nodePointer seq[]) {
	nodePointer temp = NULL;
	for (int i = 0; i < n; i++) {
		printf("\n%d : symmetric ����:\n", i);
		
		temp = seq[i];
		while (temp) {
			printf("(%p %d %p)  ",
				temp, temp->data, temp->link);
			temp = temp->link;
		}
	}
}

int main() {
	bool out[MAX_SIZE];
	nodePointer seq[MAX_SIZE];
	int i = 0, j = 0, n = 0;

	FILE* fp;
	fp = fopen("input.txt", "r");

	// ��ü���� ũ�� �Է¹ޱ�
	fscanf(fp, "%d", &n);

	printf("/* MAX_SIZE of a set S : %d */\n", MAX_SIZE);
	printf("current size of S : %d\n", n);
	printf("S = { ");
	for (i = 0; i < n - 1; i++) printf("%d, ", i);
	printf("%d }\n", i);

	// out, seq �ʱ�ȭ
	for (i = 0; i < n; i++) {
		out[i] = true;
		seq[i] = NULL;
	}

	// ����� �Է¹ޱ�, ���
	printf("input pairs : ");
	while (fscanf(fp, "%d %d", &i, &j) != EOF) {
		initRelate(i, j, seq);
		printf("%dR%d ", i, j);
	}
	printf("\n");
	
	// ���� linked list ���
	printf("\nsymmetric ���� linked List");
	printList(n, seq);

	// ��ġ�� ã�� ���ո��� �� ���
	printf("\n");
	equivalence(n, out, seq);
	printf("\n");
}