// 2023012565 kimeunjeong
#include <stdio.h>

#define CSI 033 // Control sequence introducer
// Attributes
#define RESET 0
#define BOLD 1
#define DIM 2
#define ITALIC 3
#define UNDERLINE 4
#define BLINKING 5
#define REVERSE 7
#define HIDDEN 8
#define STRIKE 9

// Colors
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

int attrs[] = {RESET, BOLD, DIM, ITALIC, UNDERLINE, BLINKING, REVERSE, HIDDEN, STRIKE};

int colors[] = {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

void textcolor(int attr, int fg, int bg) {
    char command[10];

    sprintf(command, "%c[%d;%d;%dm", CSI, attr, fg+30, bg+40);
    printf("%s", command);
}

int main() {
    int attrs_size, colors_size;
    char *msg = "ANSI Escape Sequences";

    attrs_size = ARRAY_SIZE(attrs);
    colors_size = ARRAY_SIZE(colors);

    printf("[Attribute Codes]\n");
    for (int i=0; i<attrs_size; i++) {
        textcolor(attrs[i], WHITE, BLACK);
        printf("%s\n", msg);
        textcolor(RESET, WHITE, BLACK);
    }
    printf("------------------------\n");
    printf("[Color Codes]\n");
    for (int i=0; i<colors_size; i++) {
        textcolor(0, colors[i], BLACK);
        printf("%s\n", msg);
        textcolor(RESET, WHITE, BLACK);
    }
    return 0;
}