#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_SIZE 10
#define MAX_NAME_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];  // ���ڿ� �����
} element;

element multistack[MAX_ARRAY_SIZE];  // �ϳ��� �迭�� ���� ���� ó��
int top[10];  // �� ������ top �ε���
int stack_size[10];  // �� ������ ũ��

int total_stacks;  // ���� ����

// ���� �ʱ�ȭ �Լ�
void initialize_stacks(int stacks) {
    total_stacks = stacks;
    int basic_size = MAX_ARRAY_SIZE / stacks;
    int remaining = MAX_ARRAY_SIZE % stacks;

    for (int i = 0; i < stacks; i++) {
        top[i] = -1;
        stack_size[i] = basic_size + (i == stacks - 1 ? remaining : 0);  // ������ ���ÿ� ���� ���� �Ҵ�
    }
}

// ������ ���� á���� Ȯ��
int is_full(int stack_num) {
    return top[stack_num] >= stack_size[stack_num] - 1;
}

// ������ ������� Ȯ��
int is_empty(int stack_num) {
    return top[stack_num] == -1;
}

// ���ÿ� ������ �߰�
void add_stack(int stack_num, char name[]) {
    if (stack_num >= total_stacks) {
        printf("stack number error, try again.\n");
    }
    else if (is_full(stack_num)) {
        printf("Stack %d is full\n", stack_num);
    }
    else {
        top[stack_num]++;
        strcpy(multistack[stack_num * (MAX_ARRAY_SIZE / total_stacks) + top[stack_num]].name, name);
        printf("%s is Pushed in Stack No.%d\n", name, stack_num);
    }
}

// ���ÿ��� ������ ����
void delete_stack(int stack_num) {
    if (stack_num >= total_stacks) {
        printf("stack number error, try again.\n");
    }
    else if (is_empty(stack_num)) {
        printf("Stack %d is empty\n", stack_num);
    }
    else {
        printf("%s is popped from Stack No.%d\n", multistack[stack_num * (MAX_ARRAY_SIZE / total_stacks) + top[stack_num]].name, stack_num);
        top[stack_num]--;
    }
}

// ���� ���
void sprint_stack(int stack_num) {
    if (stack_num >= total_stacks) {
        printf("stack number error, try again.\n");
    }
    else if (is_empty(stack_num)) {
        printf("Stack %d is empty\n", stack_num);
    }
    else {
        for (int i = top[stack_num]; i >= 0; i--) {
            printf("%s\n", multistack[stack_num * (MAX_ARRAY_SIZE / total_stacks) + i].name);
        }
    }
    printf("\n");
}

int main() {
    // ��ɾ� ó�� �� ���� �б�
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    char command[100];
    int stack_num;
    char name[MAX_NAME_SIZE];

    printf("How Many Stacks? : ");
    scanf("%d", &total_stacks);
   
    initialize_stacks(total_stacks);

    while (fgets(command, sizeof(command), fp)) {

        char* ptr = strtok(str, "\n");

        if (sscanf(command, "add %d %s", &stack_num, name) == 2) {
            add_stack(stack_num, name);
        }
        else if (sscanf(command, "add %d", &stack_num) == 1) {  // �̸� ���� add ��ɾ� ó��
            printf("wrong command, try again!!\n");
        }
        else if (sscanf(command, "delete %d", &stack_num) == 1) {
            delete_stack(stack_num);
        }
        else if (sscanf(command, "sprint %d", &stack_num) == 1) {
            sprint_stack(stack_num);
        }
        else if (strncmp(command, "quit", 4) == 0) {  // ������ quit ó�� �κ�
            printf("\nProgram end\n");
            for (int i = 0; i < total_stacks; i++) {
                printf("\nstack %d :\n", i);
                sprint_stack(i);
            }
            break;
        }
        else {
            printf("wrong command, try again!!\n");
        }
    }

    fclose(fp);
    return 0;
}
