#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Score {
    int classNum;
    int score;
    struct Score* next;
} Score;

typedef struct {
    Score* front;
    Score* rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int classNum, int score) {
    Score* newScore = (Score*)malloc(sizeof(Score));
    newScore->classNum = classNum;
    newScore->score = score;
    newScore->next = NULL;  // �� ���� ť�� ���̹Ƿ� next�� NULL�̾�� ��

    if (queue->rear == NULL) {  // ť�� ��� ������ front�� rear�� ��� �� ��带 ����Ŵ
        queue->front = queue->rear = newScore;
    }
    else {  // rear�� ����Ű�� ��� �ڿ� �� ��带 �߰�
        queue->rear->next = newScore;
        queue->rear = newScore;  // rear�� �� ���� ����
    }
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, nothing to dequeue.\n");
        return;
    }

    Score* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {  // ť�� ����� ��� rear�� NULL�� ����
        queue->rear = NULL;
    }

    free(temp);
}

void printQueue(Queue* queue, int subjectNum) {
    Score* current = queue->front;
    while (current != NULL) {
        printf("%d       %d       %d\n", subjectNum, current->classNum, current->score);
        current = current->next;
    }
    printf("**************************\n");
}

void readData(Queue queues[], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    int subjectNum, classNum, score;
    while (fscanf(file, "%d %d %d", &subjectNum, &classNum, &score) != EOF) {
        enqueue(&queues[subjectNum], classNum, score);  // enqueue�� ������ �߰�
    }
    fclose(file);
}

int main() {
    Queue queues[3];  // 3���� ť
    for (int i = 0; i < 3; i++) {
        initQueue(&queues[i]);
    }

    readData(queues, "input.txt");

    printf("�����ȣ, �й�, ����\n");
    printf("**************************\n");
    for (int i = 0; i < 3; i++) {
        printQueue(&queues[i], i);
    }

    return 0;
}
