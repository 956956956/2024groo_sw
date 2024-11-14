#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100

// �л� ������ ��� ����ü
typedef struct {
    int id; // unique id
    char name[MAX_NAME_SIZE];
} element;

// ȯ�� ť ����ü
typedef struct {
    element* queue; // ���� �Ҵ�� �迭
    int capacity;   // ť�� �ִ� ũ��
    int front;      // ù ��° ����� �ε���
    int rear;       // ������ ����� �ε���
    int size;       // ť�� �ִ� ����� ����
} CircularQueue;

// ť �ʱ�ȭ �Լ�
void initQueue(CircularQueue* q, int capacity) {
    q->queue = (element*)malloc(capacity * sizeof(element));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

// ť �޸� ���� �Լ�
void freeQueue(CircularQueue* q) {
    free(q->queue);
}

// ť�� ��� �ִ��� Ȯ���ϴ� �Լ�
int isEmpty(CircularQueue* q) {
    return q->size == 0;
}

// ť�� ���� á���� Ȯ���ϴ� �Լ�
int isFull(CircularQueue* q) {
    return q->size == q->capacity;
}

// ť Ȯ�� �Լ� (ũ�⸦ �� ��� �ø�)
void expandQueue(CircularQueue* q) {
    int newCapacity = q->capacity * 2;
    element* newQueue = (element*)malloc(newCapacity * sizeof(element));

    // ���� ť�� ��ҵ��� �� ť�� ����
    for (int i = 0; i < q->size; i++) {
        newQueue[i] = q->queue[(q->front + i) % q->capacity];
    }

    free(q->queue);
    q->queue = newQueue;
    q->capacity = newCapacity;
    q->front = 0;
    q->rear = q->size;

    // ť Ȯ�� �޽��� ���
    printf("queue capacity is doubled, current queue capacity is %d.\n", q->capacity);
}

// ť�� ��� �߰� (add)
void enqueue(CircularQueue* q, int id, char* name) {
    if (isFull(q)) {
        expandQueue(q);
    }
    q->queue[q->rear].id = id;
    strncpy(q->queue[q->rear].name, name, MAX_NAME_SIZE - 1);
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

// ť���� ��� ���� (delete)
void dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue empty\n");
        return;
    }
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

// ť�� ������ ����ϴ� �Լ� (qprint)
void printQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = 0; i < q->size; i++) {
        int idx = (q->front + i) % q->capacity;
        printf("%d, %s", q->queue[idx].id, q->queue[idx].name);
        if (i < q->size - 1) {
            printf("\n"); // ������ ��Ұ� �ƴ϶�� �ٹٲ� �߰�
        }
    }
    printf("\n");
}

// ��ɾ� ó�� �Լ�
void processCommands(CircularQueue* q, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char command[20];
    while (fscanf(file, "%s", command) != EOF) {
        if (strcmp(command, "add") == 0) {
            int id;
            char name[MAX_NAME_SIZE];
            fscanf(file, "%d %s", &id, name);
            enqueue(q, id, name);
        }
        else if (strcmp(command, "delete") == 0) {
            dequeue(q);
        }
        else if (strcmp(command, "qprint") == 0) {
            printQueue(q);
            printf("\n");  // qprint ȣ�� �� �� �� ���
        }
        else if (strcmp(command, "quit") == 0) {
            printf("end of program!\n");
            break;
        }
        else {
            printf("wrong command! try again!\n");
            fscanf(file, "%*[^\n]"); // ���� ���� �������� �����ϰ� �Ѿ
        }
    }

    fclose(file);
}

int main() {
    CircularQueue q;
    initQueue(&q, 2); // �ʱ� ũ�⸦ 2�� ����

    processCommands(&q, "input.txt");

    freeQueue(&q); // �޸� ����
    return 0;
}
