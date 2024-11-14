#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

typedef struct Node {
    char value;
    struct Node* left, * right;
} Node;

// ���� ����
typedef struct Stack {
    Node* nodes[MAX_EXPR_SIZE];
    int top;
} Stack;

// ���� �ʱ�ȭ
void initStack(Stack* stack) {
    stack->top = -1;
}

// ������ ������� Ȯ��
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// ���ÿ� ��带 �߰�
void push(Stack* stack, Node* node) {
    stack->nodes[++stack->top] = node;
}

// ���ÿ��� ��带 ����
Node* pop(Stack* stack) {
    if (isEmpty(stack)) return NULL;
    return stack->nodes[stack->top--];
}

// �� ��� ����
Node* newNode(char value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Postfix ǥ������ �̿��� ���� Ʈ�� ����
Node* buildExpressionTree(char* postfix) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        Node* node = newNode(ch);

        if (ch == '&' || ch == '|') {
            node->right = pop(&stack);
            node->left = pop(&stack);
        }
        else if (ch == '~') {
            node->left = pop(&stack);
        }

        push(&stack, node);
    }
    return pop(&stack);
}

// ���� Ʈ���� ���� ��ȸ�Ͽ� �������� ���
int evaluateExpression(Node* root, int a, int b, int c) {
    if (!root) return 0;

    // �ǿ������� ��� �� ��ȯ
    if (root->value == 'a') return a;
    if (root->value == 'b') return b;
    if (root->value == 'c') return c;

    // �������� ���
    int left = evaluateExpression(root->left, a, b, c);
    int right = root->right ? evaluateExpression(root->right, a, b, c) : 0;

    switch (root->value) {
    case '&': return left && right;
    case '|': return left || right;
    case '~': return !left;
    }
    return 0;
}

// ��� ���� ������ �׽�Ʈ�ϰ� �������� ���� �Ǵ� ��� ���
void findSatisfyingAssignments(Node* root) {
    printf("find true condition:\n");

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            for (int c = 0; c <= 1; c++) {
                if (evaluateExpression(root, a, b, c)) {
                    printf("a = %d, b = %d, c = %d\n", a, b, c);
                }
            }
        }
    }
}

// Ʈ���� ��� ��带 ��������� ����
void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char postfix[MAX_EXPR_SIZE];
    FILE* file = fopen("input.txt", "r");

    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    // ���Ϸκ��� postfix ǥ���� �б�
    fscanf(file, "%s", postfix);
    fclose(file);

    printf("input string(postfix): %s\n", postfix);

    // ���� Ʈ�� ����
    Node* root = buildExpressionTree(postfix);

    // ���� �Ǵ� ��� ���� ã��
    findSatisfyingAssignments(root);

    // �޸� ����
    freeTree(root);

    return 0;
}
