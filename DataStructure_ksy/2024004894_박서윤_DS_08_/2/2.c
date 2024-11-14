#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_EMPTY(first)(! (first)) // NULL�̸� 1 NULL�� �ƴϸ� 0

typedef struct listNode* listPointer;
typedef struct listNode {
    char name[30];
    char company[50];
    char gender[30];
    listPointer link;
} listNode;
listPointer first = NULL;
listPointer first_male = NULL;
listPointer first_female = NULL;

void insert(listPointer* first, listPointer x, listNode data);
void delete(listPointer* first, listPointer trail, listPointer x);
void printList(listPointer first);
listPointer reverseList(listPointer head);
listPointer mergeLists(listPointer male, listPointer female);

int main()
{
    FILE* f;
    listPointer search, search_male = NULL, search_female = NULL;
    listNode data;

    fopen_s(&f, "input.txt", "r");
    if (f == NULL)
    {
        fprintf(stderr, "cannot open the file\n");
        exit(EXIT_FAILURE);
    }

    fscanf_s(f, "%s %s %s\n", data.name, 30, data.company, 50, data.gender, 30);
    insert(&first, NULL, data);
    search = first;

    while (!feof(f)) {
        fscanf_s(f, "%s %s %s\n", data.name, 30, data.company, 50, data.gender, 30);
        insert(&first, search, data);
        search = search->link;
    }

    fclose(f);

    printf("��ü ����Ʈ\n");
    printList(first);
    puts("");


    do {
        strcpy_s(data.name, 30, first->name);
        strcpy_s(data.company, 50, first->company);
        strcpy_s(data.gender, 30, first->gender);

        if (!strcmp(data.gender, "����\0")) {
            if (first_male == NULL) {
                insert(&first_male, NULL, data);
                search_male = first_male;
            }
            else {
                insert(&first_male, search_male, data);
                search_male = search_male->link;
            }

        }

        else {
            if (first_female == NULL) {
                insert(&first_female, NULL, data);
                search_female = first_female;
            }
            else {
                insert(&first_female, search_female, data);
                search_female = search_female->link;
            }
        }
        delete(&first, NULL, first);
    } while (first != NULL);

    printf("���� ����Ʈ\n");
    printList(first_male);
    puts("");

    printf("���� ����Ʈ\n");
    printList(first_female);

    // ��ģ ����Ʈ ����� �� ���
    listPointer mergedList = mergeLists(first_male, first_female);
    printf("��ģ ����Ʈ\n");
    printList(mergedList);

    // ���� ����Ʈ ����� �� ���
    listPointer reversed = reverseList(mergedList);
    printf("��ģ ����Ʈ ���� ���\n");
    printList(reversed);

    return 0;
}

void insert(listPointer* first, listPointer x, listNode data)
{
    listPointer temp;
    temp = malloc(sizeof(*temp));
    strcpy_s(temp->name, 30, data.name);
    strcpy_s(temp->company, 50, data.company);
    strcpy_s(temp->gender, 30, data.gender);

    if (*first == NULL) {
        temp->link = NULL;
        *first = temp;
    }
    else {
        if (x == NULL)
        {
            temp->link = *first;
            *first = temp;
        }
        else {
            temp->link = x->link;
            x->link = temp;
        }
    }
}

void delete(listPointer* first, listPointer trail, listPointer x)
{
    if (trail)
        trail->link = x->link;
    else
        *first = (*first)->link;
    free(x);
}

void printList(listPointer first)
{
    for (; first; first = first->link)
        printf("(%p, %s, %s, %s, %p)\n", first, first->name, first->company, first->gender, first->link);
    printf("\n");
}

// �� ����Ʈ�� ��ġ�� �Լ�
listPointer mergeLists(listPointer male, listPointer female) {
    listPointer merged = NULL, last = NULL;

    // ������ ���� �߰�
    while (female != NULL) {
        if (merged == NULL) {
            merged = female;
            last = female;
        }
        else {
            last->link = female;
            last = female;
        }
        female = female->link;
    }

    // ������ �� ������ �߰�
    while (male != NULL) {
        if (merged == NULL) {
            merged = male;
            last = male;
        }
        else {
            last->link = male;
            last = male;
        }
        male = male->link;
    }

    return merged; // ������ ����Ʈ ��ȯ
}

// ����Ʈ�� �������� ����� �Լ�
listPointer reverseList(listPointer head) {
    listPointer prev = NULL;
    listPointer curr = head;
    listPointer next = NULL;

    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }

    return prev; // ������ ����Ʈ�� ù ��° ��� ��ȯ
}