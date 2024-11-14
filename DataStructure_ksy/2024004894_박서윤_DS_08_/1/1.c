#include <stdio.h>
#include <stdlib.h>

#define IS_EMPTY(first)(! (first))

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
} listNode;

listPointer first = NULL;

// �Լ� ����
void insert(listPointer* first, listPointer x, int data);
void delete(listPointer* first, listPointer trail, listPointer x);
void printList(listPointer first);

int main()
{
	FILE* f;
	listPointer search;
	int data[12];

	fopen_s(&f, "input.txt", "r");
	if (f == NULL)
	{
		fprintf(stderr, "cannot open the file\n");
		exit(EXIT_FAILURE);
	}

	fscanf_s(f, "%d %d %d %d %d %d\n", data, data + 1, data + 2, data + 3, data + 4, data + 5);
	fscanf_s(f, "%d %d %d %d %d %d\n", data + 6, data + 7, data + 8, data + 9, data + 10, data + 11);

	fclose(f);

	// ù ��° ��带 ���� �Ҵ��ϰ� �ʱ�ȭ
	first = malloc(sizeof(*first));
	first->data = data[0];
	first->link = NULL;

	search = first;  // ����Ʈ Ž���� ���� search �����͸� �ʱ�ȭ

	// ������ �����͸� ����Ʈ�� ����
	for (int i = 1; i < 12; i++) {

		if (first->data > data[i]) {
			insert(&first, NULL, data[i]);  // ù ��° ��庸�� ���� ��� �տ� ����
		}
		else {
			while (1) {
				if (search->link == NULL || search->link->data > data[i]) {
					insert(&first, search, data[i]);  // �ùٸ� ��ġ�� ����
					break;
				}
				search = search->link;  // ���� ���� �̵�
			}
			search = first;  // Ž�� �����͸� �ٽ� ù ��° ���� �ʱ�ȭ
		}
	}

	printList(first);


	while (1) {
		search = first;
		if (search->data % 2)
			delete(&first, NULL, search);
		else {
			while (search->link != NULL) {
				if (search->link->data % 2)  // ���� ��尡 Ȧ���� ���
					delete(&first, search, search->link);  // �ش� ��带 ����
				else
					search = search->link;  // ���� ���� �̵�
			}
		}
		if (search->link == NULL)
			break;
	}

	printf("\nAfter deleting nodes with odd value\n");

	printList(first);

	return 0;
}


void insert(listPointer* first, listPointer x, int data)
{
	listPointer temp;
	temp = malloc(sizeof(*temp));  // ���ο� ��带 ���� �Ҵ�
	temp->data = data;
	if (*first == NULL) {  // ����Ʈ�� ����ִ� ���
		temp->link = NULL;
		*first = temp;  // ù ��° ���� ����
	}
	else {
		if (x == NULL)  // ù ��° ��� �տ� �����ϴ� ���
		{
			temp->link = *first;
			*first = temp;  // ���ο� ��带 ù ��° ���� ����
		}
		else {  // �߰��̳� ���� �����ϴ� ���
			temp->link = x->link;
			x->link = temp;
		}
	}
}


void delete(listPointer* first, listPointer trail, listPointer x)
{
	if (trail)  // �߰� �Ǵ� ������ �����ϴ� ���
		trail->link = x->link;  // ���� ��尡 ������ ����� ���� ��带 ����Ŵ
	else  // ù ��° ��带 �����ϴ� ���
		*first = (*first)->link;  // ù ��° ��带 ����
	free(x);  // �޸� ����
}

void printList(listPointer first)
{
	printf("The ordered list contains:\n");
	for (; first; first = first->link)  // ����Ʈ�� ��ȸ�ϸ� �� ��� ���
		printf("(%p, %4d, %2p)\n", first, first->data, first->link);  // ����� �ּ�, ������, ���� ����� �ּ� ���
	printf("\n");
}
