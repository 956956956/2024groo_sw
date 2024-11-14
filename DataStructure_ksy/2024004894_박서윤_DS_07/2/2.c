#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 80

// ���� ����
char stack[MAX];
int top = -1;

// ���� �Լ���
void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top != -1) {
        return stack[top];
    }
    return '\0';
}

// ������ �켱���� �Լ�
int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    return -1;
}

// ����ǥ����� ����ǥ������� ��ȯ
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            // �ǿ������� ��� ��� (����ǥ����� �߰�)
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            // '(' ���ÿ� �߰�
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            // ')'�� ������ '('�� ���� ������ ���ÿ��� ���� ���
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        else {
            // �������� ���
            while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // ���ÿ� �����ִ� ������ ���
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // ���ڿ� �� ǥ��
}

int main() {
    char infix[MAX], postfix[MAX];
    FILE* fin, * fout;

    // �Է� ���� ����
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error: input file not found.\n");
        return 1;
    }

    // ��� ���� ����
    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error: cannot open output file.\n");
        fclose(fin);
        return 1;
    }

    // �Է� ���� �б�
    fscanf(fin, "%s", infix);

    // ����ǥ����� ����ǥ������� ��ȯ
    infixToPostfix(infix, postfix);

    // ��� ��� (ȭ�� �� ����)
    printf("infix expression : %s\npostfix expression : %s\n", infix, postfix);
    fprintf(fout, "%s\n", postfix);

    // ���� �ݱ�
    fclose(fin);
    fclose(fout);

    return 0;
}
