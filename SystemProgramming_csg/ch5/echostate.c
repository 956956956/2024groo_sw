#include <stdio.h>
#include <stdlib.h>
#include <termio.h>

int main(){
    struct termios info;
    int rv;

    rv = tcgetattr(0, &info);
    if(rv == -1){
        perror("tcgetatter");
        exit(EXIT_FAILURE);
    }

    if(info.c_lflag & ECHO)
        printf("echo is on, since its bi is 1\n");
    else
        printf("echo is OFF, since its bit is 0\n");
    return 0;
}