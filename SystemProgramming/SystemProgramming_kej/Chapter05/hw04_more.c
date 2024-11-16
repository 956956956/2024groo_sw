// 2023012565 kimeunjeong
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

/* 전역변수 선언 */
int PAGELEN = 0;
int LINELEN = 0;
void do_more(FILE *);
int see_more(FILE *);

int main(int ac, char *av[]) {
    FILE *fp;
    struct winsize wbuf;

    /* argc 개수가 2가 아닌 경우 오류 메시지 출력 */
    if  (ac!=2) {
        fprintf(stderr, "[Usage] ./hw04_more [filename]\n");
        return 1;
    }
    else {
        while (--ac) {
            if ((fp = fopen(*++av, "r")) != NULL) {
                /* 현재 터미널의 row, col 크기 계산 */
                if (ioctl(0, TIOCGWINSZ, &wbuf) != -1) {
                    PAGELEN = wbuf.ws_row;
                    LINELEN = wbuf.ws_col;
                }

                do_more(fp);
                fclose(fp);
            }
            else {
                exit(1);
            }
        }
    }
    return 0;
}

void do_more(FILE *fp) {                                                                                                                                                                                                                                                                        
    char line[LINELEN];
    int num_of_line = 0;
    int reply = 0;
    FILE *fp_tty = fopen("/dev/tty", "r");
    if (fp_tty == NULL) {
        exit(1);
    }
    
    while (fgets(line, LINELEN, fp) != NULL) {
        if (num_of_line == PAGELEN) {
            // NEW: directly read from keyboard
            reply = see_more(fp_tty);
            if (reply == 0) {
                break;
            }
            num_of_line -= reply;
        }
        if (fputs(line, stdout) == EOF) {
            exit(1);
        }
        num_of_line++;
    }
}

int see_more(FILE *cmd) {
    int c = 0;
    /* more? 옆에 터미널 크기 출력 */
    printf("\033[7m more?(%d x %d) \033[m", PAGELEN, LINELEN);
    while ((c = getc(cmd)) != EOF) {
        // Compile
        #ifdef DEBUG
            printf("\nsee more: %c ", c);
        #endif

        if (c == 'q')
            return 0;
        if (c == ' ')
            return PAGELEN;
        if (c== '\n') {
            // Compile
            #ifdef DEBUG
                printf("carriage return\n");
            #endif
            return 1;
        }
    }
    return 0;
}