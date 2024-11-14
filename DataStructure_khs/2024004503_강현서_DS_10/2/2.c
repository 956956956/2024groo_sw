#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	nodePointer llink;
	int data;
	nodePointer rlink;
}node;

void dinsert(nodePointer node, int num);
void ddelete(nodePointer deleted);
void printListFrnt(nodePointer head);
void printListBack(nodePointer head);

void dinsert(nodePointer node, int num) {
	nodePointer newNode = NULL;
	newNode = (nodePointer)malloc(sizeof(*newNode));
	if (!newNode) return;
	newNode->data = num;
	newNode->llink = node;
	newNode->rlink = node->rlink;

	node->rlink->llink = newNode;
	node->rlink = newNode;
}

void ddelete(nodePointer deleted) {
	deleted->llink->rlink = deleted->rlink;
	deleted->rlink->llink = deleted->llink;
	free(deleted);
}

void printListFrnt(nodePointer head) {
	int cnt = 0;
	printf("forward\n");
	nodePointer temp = head->rlink;
	while (temp != head) {
		cnt++;
		printf("(%p %5d %p)   ",
			temp->llink, temp->data, temp->rlink);
		temp = temp->rlink;
		if (cnt % 4 == 0) printf("\n");
	} 
}

void printListBack(nodePointer head) {
	int cnt = 0;
	printf("backward\n");
	nodePointer temp = head->llink;
	while (temp != head) {
		cnt++;
		printf("(%p %5d %p)   ",
			temp->llink, temp->data, temp->rlink);
		temp = temp->llink;
		if (cnt % 4 == 0) printf("\n");
	}
}

int main() {
	FILE* fp;
	fp = fopen("input.txt", "r");
	int num = 0;
	nodePointer header = NULL;
	header = (nodePointer)malloc(sizeof(*header));
	if (!header) return 0;
	header->llink = header;
	header->rlink = header;

	// ���߿���ȯ������Ʈ �����
	while (fscanf(fp, "%d ", &num) != EOF)
		dinsert(header->llink, num);

	// ���߿���ȯ������Ʈ �յڷ� ���
	printf("After creating a doubly lnked circular list with a head node :\n");
	printListFrnt(header);
	printf("\n");
	printListBack(header);

	// 50 ������ ������ ����
	nodePointer trail = header->rlink;
	while (trail != header) {			// ������ ��尡 �����Ǹ� trail = head�� ����
		trail = trail->rlink;			// �������� �̵� (2��° ������ ����)
		if (trail->llink->data <= 50)	// trail ������ data�� 50���ϸ�
			ddelete(trail->llink);		//  trail ������� ����
	}

	printf("\nAfter deleting numbers less than and equal to 50\n");
	printListFrnt(header);
	printf("\n");
	printListBack(header);
	printf("\n");

	// ���� ����
	trail = header->rlink;
	while (trail != header) {
		trail = trail->rlink;
		ddelete(trail->llink);
	}
	free(header);
}