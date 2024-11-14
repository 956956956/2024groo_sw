/*
2021114624
Park Chanjin
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int PAGELEN;
int LINELEN;

void do_more(FILE *);
int see_more(FILE *);

int main(int ac, char *av[]){
    FILE *fp;
    struct winsize wbuf;

    if (ioctl(0, TIOCGWINSZ, &wbuf) != -1) {
        PAGELEN = wbuf.ws_row;
        LINELEN = wbuf.ws_col;
	}

    if (ac != 2){
        printf("[Usage] ./hw04_more [filename]\n");
        exit(-1);
    }
    else{
        while (--ac){
            if ((fp = fopen(*++av, "r")) != NULL){
                do_more(fp);
                fclose(fp);
            }
            else{
                exit(1);
            }
        }
    }
    return 0;
}

void do_more(FILE *fp){
    char line[LINELEN];
    int num_of_line = 0;
    int reply = 0;
    FILE *fp_tty = fopen("/dev/tty", "r");
    if (fp_tty == NULL){
        exit(1);
    }
    
    while (fgets(line, LINELEN, fp) != NULL){
        if (num_of_line == PAGELEN){
            reply = see_more(fp_tty);
            if (reply == 0){
                break;
            }
            num_of_line -= reply;
        }
        if (fputs(line, stdout) == EOF){
            exit(1);
        }
        num_of_line++;
    }
}

int see_more(FILE *cmd){
    int c = 0;
    printf("\033[7m more?(%d x %d) \033[m", PAGELEN, LINELEN);
    while ((c = getc(cmd)) != EOF){
        if (c == 'q')
            return 0;
        if (c == ' ')
            return PAGELEN;
        if (c == '\n')
            return 1;
    }
    return 0;
}