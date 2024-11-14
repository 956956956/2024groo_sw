#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ROW 10
#define MAX_COL 10

// 8����: ��, �ϵ�, ��, ����, ��, ����, ��, �ϼ�
int move[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int maze[MAX_ROW][MAX_COL];
int visited[MAX_ROW][MAX_COL];
int row, col;

typedef struct {
    int x, y;
} Point;

// �ⱸ (4, 5)
Point exit_point = { 3, 4 };

// ��� ������ ���� �迭
Point path[MAX_ROW * MAX_COL];
int pathIndex = 0;

// �̷� ��� �Լ�
void printMaze() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// ��� ��� �Լ�
void printPath() {
    for (int i = 0; i < pathIndex; i++) {
        printf("%d  %d\n", path[i].x + 1, path[i].y + 1);
    }
    printf("The exit is found. Finish the program.\n");
}

// �̷� Ž�� �Լ� (��� ��Ʈ��ŷ ����)
int findPath(int x, int y) {
    // ���� ��ġ�� �ⱸ�� ���
    if (x == exit_point.x && y == exit_point.y) {
        path[pathIndex++] = (Point){ x, y };  // �ⱸ ��ǥ ����
        printPath();  // ��� ���
        return 1;
    }

    // �湮�� ���� 2�� ǥ��
    visited[x][y] = 1;
    path[pathIndex++] = (Point){ x, y };  // ���� ��ǥ ����

    // �ð�������� �̵� ���� ���� Ȯ��
    for (int i = 0; i < 8; i++) {
        int newX = x + move[i][0];
        int newY = y + move[i][1];

        // �̷� �����̰�, �̵��� �� �ִ� ���̸�, �湮���� �ʾ��� ���� �̵�
        if (newX >= 0 && newX < row && newY >= 0 && newY < col && maze[newX][newY] == 0 && !visited[newX][newY]) {
            if (findPath(newX, newY)) {
                return 1;  // �ⱸ�� �����ϸ� ��� ����
            }
        }
    }

    // �̵��� �� ���� ��� ��ο��� ���� (��Ʈ��ŷ)
    pathIndex--;
    return 0;
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("File error. Cannot open the file.\n");
        return 1;
    }

    fscanf(file, "%d %d", &row, &col);  // �̷��� ��� �� ũ�� �Է�
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fscanf(file, "%d", &maze[i][j]);  // �̷� ���� �Է�
        }
    }
    fclose(file);

    printf("The path is :\nrow col\n");
    if (!findPath(0, 0)) {  // (1,1)���� Ž�� ����
        printf("There is no way to the path.\n");
    }

    return 0;
}
