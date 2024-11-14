#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20

typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
} element;

element queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

// ȯ�� ť�� ��� �ִ��� Ȯ��
int is_empty() {
    return front == rear;
}

// ȯ�� ť�� ���� á���� Ȯ��
int is_full() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

// ť�� �����͸� �߰��ϴ� �Լ�
void add(int id, char name[]) {
    if (is_full()) {
        printf("queue is full, not added.\n");
    }
    else {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear].id = id;
        strcpy(queue[rear].name, name);
    }
}

// ť���� �����͸� �����ϴ� �Լ�
void delete() {
    if (is_empty()) {
        printf("queue is empty\n");
    }
    else {
        front = (front + 1) % MAX_QUEUE_SIZE;
    }
}

// ť�� ������ ����ϴ� �Լ�
void qprint() {
    if (is_empty()) {
        printf("queue is empty\n");
    }
    else {
        int i = (front + 1) % MAX_QUEUE_SIZE;
        while (i != (rear + 1) % MAX_QUEUE_SIZE) {
            printf("%d, %s\n", queue[i].id, queue[i].name);
            i = (i + 1) % MAX_QUEUE_SIZE;
        }
        printf("\n");
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    char command[10];
    int id;
    char name[MAX_NAME_SIZE];

    while (fscanf(file, "%s", command) != EOF) {
        if (strcmp(command, "add") == 0) {
            fscanf(file, "%d %s", &id, name);
            add(id, name);
        }
        else if (strcmp(command, "delete") == 0) {
            delete();
        }
        else if (strcmp(command, "qprint") == 0) {
            qprint();
        }
        else {
            printf("wrong command! try again!\n");
            // �߸��� ��ɿ� ���� �߰��� ó������ �ʰ� �Ѿ
            fscanf(file, "%*[^\n]"); // ���� �κ��� �����ϰ� ���� �ٷ� �̵�
        }
    }

    fclose(file);
    return 0;
}
