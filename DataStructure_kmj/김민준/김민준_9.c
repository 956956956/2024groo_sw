#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Robot {
    int identity;
    int x;
    int y;
    int speed;
    double time;
} robot;

int compare_time(const void* a, const void* b) {
    double diff = ((robot*)a)->time - ((robot*)b)->time;
    if (diff > 0) return 1;
    else if (diff < 0) return -1;
    return 0;
}

int compare_identity(const void* a, const void* b) {
    return ((robot*)a)->identity - ((robot*)b)->identity;
}

double distance(double x, double y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

double calculate_time(double distance, double speed) {
    return distance / speed;
}

int main() {
    int count;
    scanf("%d", &count);

    robot* a = (robot*)malloc(count * sizeof(robot));
    if (a == NULL) return 1;

    for (int i = 0; i < count; i++) {
        a[i].identity = i + 1;
        scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].speed);
        a[i].time = calculate_time(distance((double)a[i].x, (double)a[i].y), (double)a[i].speed);
    }

    qsort(a, count, sizeof(robot), compare_time);

    for (int i = 0; i < count; i++) {
        int j = i;
        while (j < count - 1 && a[j].time == a[j + 1].time) {
            j++;
        }
        if (j > i) {
            qsort(a + i, j - i + 1, sizeof(robot), compare_identity);
        }
        i = j;
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", a[i].identity);
    }

    free(a);
    return 0;
}
