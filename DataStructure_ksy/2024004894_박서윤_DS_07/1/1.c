#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 80

// ���� ���� ����
typedef struct {
    int data[MAX_EXPR_SIZE];
    int top;
} Stack;

// ���� �ʱ�ȭ �Լ�
void initStack(Stack* s) {
    s->top = -1;
}

// ������ ������� Ȯ���ϴ� �Լ�
int isEmpty(Stack* s) {
    return s->top == -1;
}

// ���ÿ� ���� Ǫ���ϴ� �Լ�
void push(Stack* s, int value) {
    if (s->top < MAX_EXPR_SIZE - 1) {
        s->data[++(s->top)] = value;
    }
    else {
        printf("Stack overflow!\n");
    }
}

// ���ÿ��� ���� ���ϴ� �Լ�
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    else {
        printf("Stack underflow!\n");
        exit(1);
    }
}

// ����ǥ��� ��� �Լ�
int evaluatePostfix(const char* expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            push(&s, expr[i] - '0');
        }
        else {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (expr[i]) {
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            case '%': push(&s, op1 % op2); break;
            default: printf("Unknown operator: %c\n", expr[i]); exit(1);
            }
        }
    }
    return pop(&s);
}

int main() {
    FILE* inputFile, * outputFile;
    char expr[MAX_EXPR_SIZE];

    // �Է� ���� ����
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open input.txt\n");
        return 1;
    }

    // ���� ǥ��� ���� �б�
    fscanf(inputFile, "%s", expr);
    fclose(inputFile);

    // ��� ����
    int result = evaluatePostfix(expr);

    // ����� ȭ��� ���Ͽ� ���
    printf("postfix expression : %s\nthe evaluation value = %d\n", expr, result);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open output.txt\n");
        return 1;
    }
    fprintf(outputFile, "%s = %d\n", expr, result);
    fclose(outputFile);

    return 0;
}
